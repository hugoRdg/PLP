#include "lexer.h"
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_TOKENS 100

Token* tokenize(const char* input) {
    Token* tokens = malloc(sizeof(Token) * MAX_TOKENS);
    int token_count = 0;

    while (*input != '\0' && token_count < MAX_TOKENS - 1) {
        // Ignorer les espaces
        if (isspace(*input)) {
            input++;
            continue;
        }

        // Traiter les nombres
        if (isdigit(*input) || *input == '.') {
            char* end;
            double value = strtod(input, &end);
            if (end != input) {
                tokens[token_count].type = TOKEN_NUMBER;
                tokens[token_count].value = value;
                token_count++;
                input = end;
                continue;
            }
        }

        // Traiter les opérateurs
        if (*input == '+' || *input == '-' || *input == '*' || *input == '/') {
            tokens[token_count].type = TOKEN_OPERATOR;
            tokens[token_count].operator = *input;
            token_count++;
            input++;
            continue;
        }

        // Caractère non reconnu
        tokens[token_count].type = TOKEN_ERROR;
        token_count++;
        break;
    }

    tokens[token_count].type = TOKEN_END;
    return tokens;
}

void free_tokens(Token* tokens) {
    free(tokens);
}