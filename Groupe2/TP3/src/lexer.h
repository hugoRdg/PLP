#ifndef LEXER_H
#define LEXER_H

#include <stdlib.h>

// Enumération des types de jetons
typedef enum {
    TOKEN_NUMBER,  
    TOKEN_OPERATOR, 
    TOKEN_END,     
    TOKEN_ERROR  
} TokenType;

// Structure représentant un jeton
typedef struct {
    TokenType type;  
    double value;   
    char operator;  
} Token;

// Fonction pour tokenizer une chaîne d'expressions
Token* tokenize(const char* expression, size_t* token_count);

#endif