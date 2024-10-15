#include "parseur.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

ExpressionMath parse(Token* tokens) {
    ExpressionMath expr = {0};
    int index = 0;

    // Vérifier le premier opérande
    if (tokens[index].type == TOKEN_PAREN_OPEN) {
        index++; // Passer la parenthèse ouvrante
        ExpressionMath innerExpr = parse(&tokens[index]); // Appel récursif

        if (innerExpr.erreur) {
            return innerExpr; // Retourner l'erreur trouvée
        }

        expr.operande1 = innerExpr.operande1; // Enregistrer le résultat
        index += innerExpr.index; // Ajuster l'index après l'expression

        // Vérifier la parenthèse fermante
        if (tokens[index].type != TOKEN_PAREN_CLOSE) {
            expr.erreur = 1;
            expr.messageErreur = "Parenthèse fermante attendue";
            return expr;
        }
        index++; // Passer la parenthèse fermante
    } else if (tokens[index].type != TOKEN_NUMBER) {
        expr.erreur = 1;
        expr.messageErreur = "Nombre attendu";
        return expr;
    } else {
        expr.operande1 = tokens[index].value; // Enregistrer le premier opérande
        index++;
    }

    // Vérifier s'il reste des tokens pour l'opérateur
    if (tokens[index].type != TOKEN_OPERATOR) {
        expr.erreur = 1;
        expr.messageErreur = "Opérateur attendu";
        return expr;
    }
    expr.operation = tokens[index].operator;
    index++;

    // Vérifier le deuxième opérande
    if (tokens[index].type == TOKEN_PAREN_OPEN) {
        index++; // Passer la parenthèse ouvrante
        ExpressionMath innerExpr = parse(&tokens[index]); // Appel récursif

        if (innerExpr.erreur) {
            return innerExpr; // Retourner l'erreur trouvée
        }

        expr.operande2 = innerExpr.operande1; // Enregistrer le résultat
        index += innerExpr.index; // Ajuster l'index après l'expression

        // Vérifier la parenthèse fermante
        if (tokens[index].type != TOKEN_PAREN_CLOSE) {
            expr.erreur = 1;
            expr.messageErreur = "Parenthèse fermante attendue";
            return expr;
        }
        index++; // Passer la parenthèse fermante
    } else if (tokens[index].type != TOKEN_NUMBER) {
        expr.erreur = 1;
        expr.messageErreur = "Nombre attendu";
        return expr;
    } else {
        expr.operande2 = tokens[index].value; // Enregistrer le deuxième opérande
        index++;
    }

    expr.index = index; // Mettre à jour le nombre de tokens traités

    return expr;
}