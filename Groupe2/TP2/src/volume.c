#include <math.h>
#include "sphere.h"

// Fonction pour calculer le volume d'une sphère
float calculer_volume(float rayon) {
    return (4.0 / 3.0) * M_PI * pow(rayon, 3);
}

/*
    1. Préprocesseur (gcc -E volume.c -o volume.i)
       - Le préprocesseur gère les directives #include pour insérer <math.h> (qui permet d'utiliser M_PI et pow) 
         et "sphere.h" (pour déclarer la fonction `calculer_volume`).
    
    2. Compilation (gcc -O3 -c volume.i -o volume.o)
       - Le compilateur convertit le code en assembleur avec des optimisations agressives (inlining, optimisation des boucles).
    
    3. Assemblage (volume.o)
       - Traduction du code assembleur en binaire objet (volume.o).
*/