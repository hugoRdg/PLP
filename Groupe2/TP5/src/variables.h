#ifndef VARIABLES_H
#define VARIABLES_H

#include <stdbool.h>

typedef enum {
    ENTIER,
    REEL,
    CHAINE
} TypeVariable;

typedef struct {
    char* nom;
    TypeVariable type;
    union {
        int entier;
        double reel;
        char* chaine;
    } valeur;
} Variable;

bool ajouter_variable(const char* nom, TypeVariable type, void* valeur);
Variable* obtenir_variable(const char* nom);
bool verifier_type_variable(const char* nom, TypeVariable type);
void liberer_variables();  

#endif
