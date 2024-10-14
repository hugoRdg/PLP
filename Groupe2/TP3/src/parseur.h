#ifndef PARSEUR_H
#define PARSEUR_H

#include "lexer.h"

typedef struct {
    int erreur;
    const char *messageErreur;
    char operation;
    double operande1;
    double operande2;
    int index;
} ExpressionMath;

ExpressionMath parse(Token* tokens);

#endif