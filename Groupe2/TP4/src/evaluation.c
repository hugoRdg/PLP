#include "evaluation.h"
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

#define MAX_PILE 100

double evaluer(ExpressionMath expr) {
    switch(expr.operation) {
        case '+':
            return expr.operande1 + expr.operande2;
        case '-':
            return expr.operande1 - expr.operande2;
        case '*':
            return expr.operande1 * expr.operande2;
        case '/':
            if (fabs(expr.operande2) < 1e-10) {
                fprintf(stderr, "Erreur : Division par zero impossible\n");
                return 0;
            }
            return expr.operande1 / expr.operande2;
        default:
            fprintf(stderr, "Erreur : Operateur non reconnu\n");
            return 0;
    }
}

double evaluer_postfixe(const char* expression_postfixee) {
    double pile[MAX_PILE];
    int sommet = -1;

    // Création d'une copie de l'expression postfixée
    char expression_copy[1024]; // Buffer pour stocker l'expression postfixée
    strncpy(expression_copy, expression_postfixee, sizeof(expression_copy)); // Copie de l'expression
    expression_copy[sizeof(expression_copy) - 1] = '\0'; // Assure que la chaîne est terminée

    // Utilisation de strtok pour séparer les nombres et opérateurs dans l'expression
    const char* token = strtok(expression_copy, " ");

    while (token != NULL) {
        // Vérifie si le token est un nombre (entier ou décimal)
        if (isdigit(token[0]) || (token[0] == '-' && isdigit(token[1]))) {
            // Pousse les nombres sur la pile
            pile[++sommet] = atof(token);
        } else {
            // Opérateur, dépile deux valeurs pour effectuer l'opération
            if (sommet < 1) {
                fprintf(stderr, "Erreur : Expression postfixe invalide\n");
                return 0;
            }

            // Dépile les deux valeurs du sommet de la pile
            double b = pile[sommet--];
            double a = pile[sommet--];
            double resultat = 0;

            // Évaluation de l'opération en fonction de l'opérateur
            switch (token[0]) {
                case '+': resultat = a + b; break;
                case '-': resultat = a - b; break;
                case '*': resultat = a * b; break;
                case '/':
                    // Vérifie si le diviseur est zéro pour éviter la division par zéro
                    if (fabs(b) < 1e-10) {
                        fprintf(stderr, "Erreur : Division par zero\n");
                        return 0;
                    }
                    resultat = a / b;
                    break;
                default:
                    fprintf(stderr, "Erreur : Operateur non reconnu\n");
                    return 0;
            }
            // Pousse le résultat de l'opération sur la pile
            pile[++sommet] = resultat;
        }
        // Récupère le prochain token
        token = strtok(NULL, " ");
    }

    if (sommet != 0) {
        fprintf(stderr, "Erreur : Expression postfixée invalide\n");
        return 0;
    }
    return pile[sommet];
}