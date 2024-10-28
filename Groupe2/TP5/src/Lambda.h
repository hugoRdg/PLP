#ifndef LAMBDA_H
#define LAMBDA_H

#include "lexer.h"
#include "variables.h"

typedef struct {
    char variable;          
    char* expression;        
    char* argument;       
    int erreur;            
    char* messageErreur; 
} ExpressionLambda;

// Analyse une expression lambda et retourne sa structure
ExpressionLambda parser_lambda(const char* input);

// Évalue une expression lambda
double evaluer_lambda(ExpressionLambda expr);

// Libère la mémoire allouée pour une expression lambda
void liberer_expression_lambda(ExpressionLambda* expr);

#endif