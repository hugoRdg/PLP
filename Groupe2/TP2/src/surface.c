#include <math.h>
#include "sphere.h"

// Fonction pour calculer la surface d'une sphère
float calculer_surface(float rayon) {
    return 4 * M_PI * pow(rayon, 2);
}

/*
    1. Préprocesseur (gcc -E surface.c -o surface.i)
       - Le préprocesseur gère les directives #include pour insérer <math.h> (qui permet d'utiliser M_PI et pow) 
         et "sphere.h" (pour déclarer la fonction `calculer_surface`).
    
    2. Compilation (gcc -O3 -c surface.i -o surface.o)
       - Le compilateur convertit le code en assembleur avec des optimisations agressives (inlining, optimisation des boucles).
    
    3. Assemblage (surface.o)
       - Traduction du code assembleur en binaire objet (surface.o).
*/