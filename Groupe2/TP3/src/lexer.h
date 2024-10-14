#ifndef LEXER_H
#define LEXER_H

#include <stdlib.h>

// Enumération des types de jetons
typedef enum {
    TOKEN_NUMBER,
    TOKEN_OPERATOR,
    TOKEN_PAREN_OPEN,
    TOKEN_PAREN_CLOSE,
    TOKEN_END,
    TOKEN_ERROR
} TokenType;

// Structure représentant un jeton
typedef struct {
    TokenType type;
    double value;   
    char operator;
} Token;

// Fonction pour tokenizer une chaîne
Token* tokenize(const char* input);

// Fonction pour libérer la mémoire allouée pour les tokens
void free_tokens(Token* tokens);

#endif