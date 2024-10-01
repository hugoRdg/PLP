#include "parseur.h"
#include <stdio.h>
#include <stdlib.h>

Expression* parse(Token* tokens, size_t token_count) {
    Expression* expr = malloc(sizeof(Expression));
    int op_found = 0; // L'opérateur a été trouvé

    for (size_t i = 0; i < token_count; i++) {
        if (tokens[i].type == TOKEN_NUMBER) {
            if (!op_found) {
                // Le premier opérande
                expr->operand1 = tokens[i].value;
                op_found = 1;
            } else {
                // Le deuxième opérande
                expr->operand2 = tokens[i].value;
            }
        } else if (tokens[i].type == TOKEN_OPERATOR) {
            // Un opérande avant l'opérateur
            if (op_found && i + 1 < token_count && tokens[i + 1].type == TOKEN_NUMBER) {
                expr->operator = tokens[i].operator; // Enregistrer l'opérateur
            } else {
                free(expr);
                return NULL; // opérateur mal placé
            }
        }
    }

    // Vérifier si l'expression est complète
    if (!op_found || tokens[token_count - 1].type != TOKEN_NUMBER) {
        free(expr);
        return NULL;
    }

    return expr;
}