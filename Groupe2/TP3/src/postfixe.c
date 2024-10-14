#include "postfixe.h"
#include <string.h>
#include <stdio.h>

#define MAX_PILE 100

// Priorité des opérateurs
int priorite(char operateur) {
    switch (operateur) {
        case '+':
        case '-': return 1;
        case '*':
        case '/': return 2;
        default: return 0;
    }
}

// Conversion infixée -> postfixée
void infixe_vers_postfixe(const Token *tokens, char *output) {
    char pile[MAX_PILE]; // Pile pour stocker les opérateurs
    int sommet = -1; // Indicateur de la position actuelle du sommet de la pile
    output[0] = '\0'; // Initialisation de la chaîne de sortie

    // Parcourt chaque token jusqu'à la fin
    for (int i = 0; tokens[i].type != TOKEN_END; i++) {
        Token t = tokens[i];

        if (t.type == TOKEN_NUMBER) {
            char nombre[32];
            snprintf(nombre, sizeof(nombre), "%.2f ", t.value); // Convertit le nombre en texte
            strcat(output, nombre); // Ajoute le nombre à la sortie
        }
        else if (t.type == TOKEN_OPERATOR) {
            // Dépile les opérateurs de priorité supérieure ou égale jusqu'à en trouver un de priorité inférieure
            while (sommet >= 0 && priorite(pile[sommet]) >= priorite(t.operator)) {
                char op[3] = {pile[sommet--], ' ', '\0'}; // Retire l'opérateur du sommet
                strcat(output, op); // Ajoute l'opérateur à la sortie
            }
            // Empile l'opérateur actuel
            pile[++sommet] = t.operator;
        }
        else if (t.type == TOKEN_PAREN_OPEN) {
            // Pousse la parenthèse ouvrante sur la pile
            pile[++sommet] = '(';
        }
        else if (t.type == TOKEN_PAREN_CLOSE) {
            // Dépile jusqu'à la parenthèse ouvrante
            while (sommet >= 0 && pile[sommet] != '(') {
                char op[3] = {pile[sommet--], ' ', '\0'}; // Retire l'opérateur du sommet
                strcat(output, op); // Ajoute l'opérateur à la sortie
            }
            // Retire la parenthèse ouvrante
            if (sommet >= 0) {
                sommet--; // Retire la parenthèse ouvrante
            }
        }
    }

    // Dépile tous les opérateurs restants et les ajoute à la sortie
    while (sommet >= 0) {
        char op[3] = {pile[sommet--], ' ', '\0'};
        strcat(output, op);
    }
}