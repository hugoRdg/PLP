#include "evaluation.h"
#include <stdio.h>
#include <stdlib.h>

// Fonction pour évaluer une expression mathématique
double evaluate(Expression* expr, char* error_message) {
    if (!expr) {
        snprintf(error_message, 256, "Expression non valide.");
        return 0.0;
    }

    // Gestion des différents cas :
    switch (expr->operator) {
        case '+':
            return expr->operand1 + expr->operand2;
        case '-':
            return expr->operand1 - expr->operand2;
        case '*':
            return expr->operand1 * expr->operand2;
        case '/':
            if (expr->operand2 == 0) // Gestion de l'erreur pour la division par 0
            {
                snprintf(error_message, 256, "Erreur : On ne peut pas diviser par zéro.");
                return 0.0;
            }
            return expr->operand1 / expr->operand2;
        default:
            snprintf(error_message, 256, "Erreur : opérateur non reconnu.");
            return 0.0;
    }
}
