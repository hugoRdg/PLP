// Directive de préprocesseur pour inclure la bibliothèque mathématique
#include <math.h>  // Pour utiliser la constante M_PI

#include <stdio.h> 

// Fonction pour calculer l'aire d'un cercle
float calculer_aire(float rayon) {  
    // Utilisation de la constante pi de la bibliothèque mathématique
    return M_PI * rayon * rayon;
}

// Point d'entrée du programme
int main() {
    float rayon = 5.0;
    float aire = calculer_aire(rayon);
    // Affichage du résultat
    printf("L'aire du cercle de rayon %.2f est %.2f\n", rayon, aire);
    return 0;
}


/* Chaîne de compilation et ce qu'il se passe à chaque étape :

1. Préprocesseur (gcc -E aire.c -o aire.i)
   - Le préprocesseur gère les directives comme #include. Il remplace les macros, insère les bibliothèques et génère un fichier intermédiaire (aire.i) contenant le code source C modifié.

2. Compilation (gcc -O2 -S aire.i -o aire.s)
   - Le compilateur convertit le code en assembleur. L'option -O2 active des optimisations modérées comme enlever le code inutile et la gestion efficace des boucles. Le fichier généré (aire.s) contient ce code en assembleur.

3. Assemblage (gcc -c aire.s -o aire.o)
   - L'assembleur traduit le code assembleur en code binaire objet (aire.o), un fichier machine qui n'est pas encore exécutable à ce stade.

4. Édition de liens (gcc aire.o -lm -o aire)
   - L'éditeur de liens combine le fichier objet avec les bibliothèques nécessaires. Il génère le fichier exécutable final (aire).

5. Exécution (./aire)
   - Le programme binaire exécutable calcule et affiche l'aire du cercle.
   
*/