#include "variables.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define TAILLE_TABLE 100
static Variable table_variables[TAILLE_TABLE];
static int nb_variables = 0;

//Permet d'ajouter une variable 
bool ajouter_variable(const char* nom, TypeVariable type, void* valeur) {
    for (int i = 0; i < nb_variables; i++) {
        if (strcmp(table_variables[i].nom, nom) == 0) {
            return false; // La variable existe déjà
        }
    }

    Variable var;
    var.nom = strdup(nom);
    var.type = type;
    switch (type) {
        case ENTIER: var.valeur.entier = *(int*)valeur; break;
        case REEL: var.valeur.reel = *(double*)valeur; break;
        case CHAINE: var.valeur.chaine = strdup((char*)valeur); break;
    }

    table_variables[nb_variables++] = var;   
    return true;
}

//Permet d'obtenir une variable
Variable* obtenir_variable(const char* nom) {
    for (int i = 0; i < nb_variables; i++) {
        if (strcmp(table_variables[i].nom, nom) == 0) {
            return &table_variables[i];
        }
    }
    return NULL;
}

//permet de vérifier le type d'une variable
bool verifier_type_variable(const char* nom, TypeVariable type) {
    Variable* var = obtenir_variable(nom);
    return var && var->type == type;
}

//Permet de libérer la variable
void liberer_variables() {
    for (int i = 0; i < nb_variables; i++) {
        free(table_variables[i].nom);
        if (table_variables[i].type == CHAINE) {
            free(table_variables[i].valeur.chaine);
        }
    }
}
