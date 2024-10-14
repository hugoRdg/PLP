#include "parseur.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

ExpressionMath parse(Token* tokens) {
    ExpressionMath expr = {0};
    int index = 0;

    // Vérifier le premier opérande
    if (tokens[index].type != TOKEN_NUMBER) {
        expr.erreur = 1;
        expr.messageErreur = "Nombre attendu"; 
        return expr;
    }
    expr.operande1 = tokens[index].value;
    index++;

    // Vérifier l'opérateur
    if (tokens[index].type != TOKEN_OPERATOR) {
        expr.erreur = 1;
        expr.messageErreur = "Operateur attendu";
        return expr;
    }
    expr.operation = tokens[index].operator;
    index++;

    // Vérifier le deuxième opérande
    if (tokens[index].type != TOKEN_NUMBER) {
        expr.erreur = 1;
        expr.messageErreur = "Nombre attendu";
        return expr;
    }
    expr.operande2 = tokens[index].value;
    index++;

    // Vérifier s'il reste des tokens sans donner d'erreur si c'est une conversion postfixée
    if (tokens[index].type != TOKEN_END && tokens[index].type != TOKEN_OPERATOR) {
        expr.erreur = 1;
        expr.messageErreur = "Fin d'expression inattendue";
        return expr;
    }

    return expr;
}