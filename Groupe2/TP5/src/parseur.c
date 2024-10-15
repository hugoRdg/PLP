#include "parseur.h"
#include "variables.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void enleve_espace(char* str);
void analyser_affectation(char* nom, char* valeur_str);
void afficher_variable(Variable* var);

ExpressionMath parse(Token* tokens) {
    ExpressionMath expr = {0};
    int index = 0;

    // Vérifier le premier opérande
    if (tokens[index].type == TOKEN_PAREN_OPEN) {
        index++; // Passer la parenthèse ouvrante
        ExpressionMath innerExpr = parse(&tokens[index]); // Appel récursif

        if (innerExpr.erreur) {
            return innerExpr; // Retourner l'erreur trouvée
        }

        expr.operande1 = innerExpr.operande1; // Enregistrer le résultat
        index += innerExpr.index; // Ajuster l'index après l'expression

        // Vérifier la parenthèse fermante
        if (tokens[index].type != TOKEN_PAREN_CLOSE) {
            expr.erreur = 1;
            expr.messageErreur = "Parenthèse fermante attendue";
            return expr;
        }
        index++; // Passer la parenthèse fermante
    } else if (tokens[index].type != TOKEN_NUMBER) {
        expr.erreur = 1;
        expr.messageErreur = "Nombre attendu";
        return expr;
    } else {
        expr.operande1 = tokens[index].value; // Enregistrer le premier opérande
        index++;
    }

    // Vérifier s'il reste des tokens pour l'opérateur
    if (tokens[index].type != TOKEN_OPERATOR) {
        expr.erreur = 1;
        expr.messageErreur = "Opérateur attendu";
        return expr;
    }
    expr.operation = tokens[index].operator;
    index++;

    // Vérifier le deuxième opérande
    if (tokens[index].type == TOKEN_PAREN_OPEN) {
        index++; // Passer la parenthèse ouvrante
        ExpressionMath innerExpr = parse(&tokens[index]); // Appel récursif

        if (innerExpr.erreur) {
            return innerExpr; // Retourner l'erreur trouvée
        }

        expr.operande2 = innerExpr.operande1; // Enregistrer le résultat
        index += innerExpr.index; // Ajuster l'index après l'expression

        // Vérifier la parenthèse fermante
        if (tokens[index].type != TOKEN_PAREN_CLOSE) {
            expr.erreur = 1;
            expr.messageErreur = "Parenthèse fermante attendue";
            return expr;
        }
        index++; // Passer la parenthèse fermante
    } else if (tokens[index].type != TOKEN_NUMBER) {
        expr.erreur = 1;
        expr.messageErreur = "Nombre attendu";
        return expr;
    } else {
        expr.operande2 = tokens[index].value; // Enregistrer le deuxième opérande
        index++;
    }

    expr.index = index; // Mettre à jour le nombre de tokens traités

    return expr;
}

void enleve_espace(char* str) {
    char* p1 = str; // Pointeur de lecture
    char* p2 = str; // Pointeur d'écriture

    // Passer les espaces initiaux
    while (*p1 == ' ') p1++;

    // Déplacer les caractères non-espaces
    while (*p1) {
        if (*p1 != ' ') {
            *p2++ = *p1;
        }
        p1++;
    }

    // Terminer la chaîne
    *p2 = '\0';

    // Passer les espaces finaux (optionnel)
    while (p2 > str && *(p2 - 1) == ' ') {
        p2--;
    }
    *p2 = '\0';
}

void analyser_ligne(char* ligne) {
    char* nom_var = strtok(ligne, "=");
    char* valeur_str = strtok(NULL, "=");

    enleve_espace(nom_var);
    
    if (valeur_str) {
        enleve_espace(valeur_str); // Ne pas oublier d'enlever les espaces
        // Gestion de l'affectation
        analyser_affectation(nom_var, valeur_str);
    } else {
        // Gestion d'accès à une variable
        Variable* var = obtenir_variable(nom_var);
        if (var) {
            afficher_variable(var);
        } else {
            // Ne pas afficher de message d'erreur ici pour éviter le message de commande non reconnue
            printf("Erreur : la variable %s n'est pas définie\n", nom_var);
        }
    }
}

void analyser_affectation(char* nom, char* valeur_str) {
    // Vérifier si une valeur a été fournie pour l'affectation
    if (!valeur_str) {
        printf("Erreur : aucune valeur fournie pour %s\n", nom);
        return;
    }

    // Enlever les espaces autour de la chaîne de valeur
    enleve_espace(valeur_str);
    Variable* var = obtenir_variable(nom); // Obtenir la variable existante (s'il y en a)
    TypeVariable type; // Déclaration de la variable pour le type

    // Vérifier si la valeur est un nombre réel (contient un point décimal)
    if (strchr(valeur_str, '.')) {
        type = REEL; // Définir le type comme nombre réel
        double val = atof(valeur_str); // Convertir la chaîne en double

        // Si la variable existe déjà
        if (var) {
            // Vérifier le type de la variable
            if (verifier_type_variable(nom, type)) {
                var->valeur.reel = val; // Mettre à jour la valeur
                printf("Variable %s redefinie avec la valeur %.2f (nombre reel)\n", nom, val);
            } else {
                printf("Erreur : changement de type non autorise pour la variable %s\n", nom);
            }
        } else {
            // Ajouter la variable avec sa valeur et son type
            ajouter_variable(nom, type, &val);
            printf("Variable %s definie avec la valeur %.2f (nombre reel)\n", nom, val); // Afficher le résultat
        }

    // Vérifier si la valeur est un entier
    } else if (isdigit(valeur_str[0]) || (valeur_str[0] == '0' && valeur_str[1] == '\0')) {
        type = ENTIER; // Définir le type comme entier
        int val = atoi(valeur_str); // Convertir la chaîne en entier

        // Si la variable existe déjà
        if (var) {
            // Vérifier le type de la variable
            if (verifier_type_variable(nom, type)) {
                var->valeur.entier = val; // Mettre à jour la valeur
                printf("Variable %s redefinie avec la valeur %d (entier)\n", nom, val);
            } else {
                printf("Erreur : changement de type non autorise pour la variable %s\n", nom);
            }
        } else {
            // Ajouter la variable avec sa valeur et son type
            ajouter_variable(nom, type, &val);
            printf("Variable %s definie avec la valeur %d (entier)\n", nom, val); // Afficher le résultat
        }

    // Vérifier si la valeur est une chaîne de caractères (entourée de guillemets)
    } else if (valeur_str[0] == '\"' && valeur_str[strlen(valeur_str) - 1] == '\"') {
        type = CHAINE; // Définir le type comme chaîne
        valeur_str[strlen(valeur_str) - 1] = '\0'; // Retirer le guillemet fermant

        // Si la variable existe déjà
        if (var) {
            // Vérifier le type de la variable
            if (verifier_type_variable(nom, type)) {
                strcpy(var->valeur.chaine, valeur_str + 1); // Mettre à jour la valeur
                printf("Variable %s redefinie avec la valeur \"%s\" (chaine de caracteres)\n", nom, valeur_str + 1);
            } else {
                printf("Erreur : changement de type non autorise pour la variable %s\n", nom);
            }
        } else {
            // Ajouter la variable avec sa valeur et son type
            ajouter_variable(nom, type, valeur_str + 1); // Retirer le guillemet ouvrant
            printf("Variable %s definie avec la valeur \"%s\" (chaine de caracteres)\n", nom, valeur_str + 1); // Afficher le résultat
        }

    } else {
        // Si aucun des formats attendus n'est respecté, afficher une erreur
        printf("Erreur : format de valeur incorrect pour %s\n", nom);
    }
}

void afficher_variable(Variable* var) {
    switch (var->type) {
        case ENTIER: printf("%d\n", var->valeur.entier); break;
        case REEL: printf("%.2f\n", var->valeur.reel); break;
        case CHAINE: printf("%s\n", var->valeur.chaine); break;
    }
}