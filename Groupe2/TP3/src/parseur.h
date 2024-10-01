#ifndef PARSEUR_H
#define PARSEUR_H

#include "lexer.h"

// Structure représentant une opération mathématique
typedef struct {
    char operator;   
    double operand1; 
    double operand2;
} Expression;

// Fonction pour parser une liste de jetons et créer une expression
Expression* parse(Token* tokens, size_t token_count);

#endif
