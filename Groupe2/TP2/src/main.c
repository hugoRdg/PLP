#include <stdio.h>
#include "sphere.h"

int main() {
    float rayon = 5.0;
    float volume = calculer_volume(rayon);
    float surface = calculer_surface(rayon);

    printf("Le volume de la sphère de rayon %.2f est %.2f\n", rayon, volume);
    printf("La surface de la sphère de rayon %.2f est %.2f\n", rayon, surface);

    return 0;
}

/*
    1. Préprocesseur (gcc -E main.c -o main.i)
       - Le préprocesseur gère les directives #include pour insérer <stdio.h> (pour l'affichage) et "sphere.h" (pour accéder aux fonctions de calcul).

    2. Compilation (gcc -O3 -c main.i -o main.o)
       - Le compilateur convertit le code en assembleur avec des optimisations agressives activées par l'option -O3.
    
    3. Assemblage (main.o)
       - Traduction du code assembleur en binaire objet (main.o).

    4. Édition de liens (gcc main.o volume.o surface.o -lm -o sphere)
       - L'éditeur de liens combine tous les fichiers objets (main.o, volume.o, surface.o) et la bibliothèque mathématique (-lm).
       - Il génère l'exécutable final nommé "sphere".
    
    5. Exécution (./sphere)
       - Exécution du programme binaire pour calculer et afficher le volume et la surface de la sphère.
*/