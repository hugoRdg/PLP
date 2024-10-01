#include "lexer.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <malloc.h>

Token* tokenize(const char* expression, size_t* token_count) {
    size_t capacity = 10; // Capacité initiale pour les jetons
    Token* tokens = malloc(capacity * sizeof(Token)); // Tableau dynamique de jetons
    *token_count = 0;

    for (size_t i = 0; i < strlen(expression);) {
        // On ignore les espaces
        if (isspace(expression[i])) {
            i++;
            continue;
        }

        // Nombres
        if (isdigit(expression[i]) || (expression[i] == '.' && isdigit(expression[i + 1]))) {
            char* end;
            double value = strtod(&expression[i], &end);
            if (end == &expression[i]) { // Vérification d'erreur
                free(tokens);
                return NULL;
            }
            tokens[*token_count].type = TOKEN_NUMBER;
            tokens[*token_count].value = value;
            (*token_count)++;
            i = end - expression; // Mise à jour de l'index
        }
        // Opérateurs
        else if (strchr("+-*/", expression[i]) != NULL) {
            tokens[*token_count].type = TOKEN_OPERATOR;
            tokens[*token_count].operator = expression[i];
            (*token_count)++;
            i++;
        }
        // Erreurs de syntaxe
        else {
            tokens[*token_count].type = TOKEN_ERROR;
            free(tokens);
            return NULL;
        }

        // Réallocation
        if (*token_count >= capacity) {
            capacity *= 2;
            tokens = realloc(tokens, capacity * sizeof(Token));
        }
    }

    tokens[*token_count].type = TOKEN_END; // Fin des jetons
    return tokens;
}
