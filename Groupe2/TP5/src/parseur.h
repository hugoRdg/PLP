#ifndef PARSEUR_H
#define PARSEUR_H

#include "lexer.h"
#include "variables.h"
#include "evaluation.h"

void analyser_ligne(char* ligne);
void analyser_affectation(char* nom, char* valeur_str);

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