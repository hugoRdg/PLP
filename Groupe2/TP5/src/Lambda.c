#include "lambda.h"
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include "lexer.h"
#include "postfixe.h"
#include "evaluation.h"

// Fonction utilitaire pour vérifier si une chaîne est un nombre
static bool est_nombre(const char* str) {
    char* endptr;
    strtod(str, &endptr);
    return *endptr == '\0';
}

// Fonction pour remplacer toutes les occurrences d'une variable dans une expression
static char* substituer_variable(const char* expression, char variable, const char* valeur) {
    int taille_max = strlen(expression) * 2;
    char* resultat = malloc(taille_max);
    char* curseur = resultat;
    
    while (*expression) {
        if (*expression == variable && 
            (expression == expression || !isalnum(*(expression-1))) &&
            (!isalnum(*(expression+1)))) {
            strcpy(curseur, valeur);
            curseur += strlen(valeur);
        } else {
            *curseur++ = *expression;
        }
        expression++;
    }
    *curseur = '\0';
    
    return resultat;
}

// Parser Lambda
ExpressionLambda parser_lambda(const char* input) {
    ExpressionLambda expr = {0};
    
    // Vérifier le format de base
    if (strncmp(input, "(lambda ", 7) != 0) {
        expr.erreur = 1;
        expr.messageErreur = "Format invalide: doit commencer par '(lambda '";
        return expr;
    }
    
    // Extraire la variable
    const char* p = input + 7;
    while (isspace(*p)) p++;
    expr.variable = *p;
    
    // Vérifier le point après la variable
    p++;
    while (isspace(*p)) p++;
    if (*p != '.') {
        expr.erreur = 1;
        expr.messageErreur = "Format invalide: point manquant après la variable";
        return expr;
    }
    p++;
    
    // Extraire l'expression mathématique
    const char* debut_expr = p;
    int parentheses = 0;
    while (*p) {
        if (*p == '(') parentheses++;
        else if (*p == ')') {
            parentheses--;
            if (parentheses < 0) break;
        }
        p++;
    }
    
    if (parentheses >= 0) {
        expr.erreur = 1;
        expr.messageErreur = "Expression mal formée: parenthèses non équilibrées";
        return expr;
    }
    
    // Allouer et copier l'expression
    int longueur_expr = p - debut_expr;
    expr.expression = malloc(longueur_expr + 1);
    strncpy(expr.expression, debut_expr, longueur_expr);
    expr.expression[longueur_expr] = '\0';
    
    // Extraire l'argument
    p++;
    while (isspace(*p)) p++;
    
    // Copier l'argument jusqu'à la fin ou un espace
    const char* debut_arg = p;
    while (*p && !isspace(*p)) p++;
    expr.argument = malloc(p - debut_arg + 1);
    strncpy(expr.argument, debut_arg, p - debut_arg);
    expr.argument[p - debut_arg] = '\0';
    
    return expr;
}

// Evaluation de lambda
double evaluer_lambda(ExpressionLambda expr) {
    if (expr.erreur) {
        printf("Erreur lors du parsing: %s\n", expr.messageErreur);
        return 0;
    }
    
    // Obtenir la valeur de l'argument
    char valeur_str[32];
    if (est_nombre(expr.argument)) {
        strcpy(valeur_str, expr.argument);
    } else {
        Variable* var = obtenir_variable(expr.argument);
        if (!var) {
            printf("Erreur : la variable %s n'est pas définie\n", expr.argument);
            return 0;
        }
        if (var->type == ENTIER) {
            snprintf(valeur_str, sizeof(valeur_str), "%d", var->valeur.entier);
        } else if (var->type == REEL) {
            snprintf(valeur_str, sizeof(valeur_str), "%.2f", var->valeur.reel);
        } else {
            printf("Erreur : type de variable incompatible\n");
            return 0;
        }
    }
    
    // Substituer la variable dans l'expression
    char* expr_substituee = substituer_variable(expr.expression, expr.variable, valeur_str);
    
    // Tokenizer et évaluer l'expression
    Token* tokens = tokenize(expr_substituee);
    if (tokens) {
        char expression_postfixee[1024];
        infixe_vers_postfixe(tokens, expression_postfixee);
        
        if (strlen(expression_postfixee) > 0) {
            double resultat = evaluer_postfixe(expression_postfixee);
            free(expr_substituee);
            free_tokens(tokens);
            return resultat;
        }
    }
    
    free(expr_substituee);
    return 0;
}

void liberer_expression_lambda(ExpressionLambda* expr) {
    if (expr) {
        free(expr->expression);
        free(expr->argument);
        expr->expression = NULL;
        expr->argument = NULL;
    }
}