#ifndef EVALUATION_H
#define EVALUATION_H

#include "parseur.h"

double evaluer(ExpressionMath expr);
double evaluer_postfixe(const char* expression_postfixee);

#endif