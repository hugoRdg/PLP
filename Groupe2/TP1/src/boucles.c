#include <stdio.h>

// int main() {
//     int taille;
    
//     // Demande la taille du triangle
//     printf("Entrez la taille du triangle (inferieure a 10) : ");
//     scanf("%d", &taille);

//     // Validation de la taille
//     if (taille >= 10) {
//         printf("La taille doit etre inferieure a 10.\n");
//         return 1;
//     }

//     // Affichage du triangle avec une boucle for
//     for (int i = 1; i <= taille; i++) {
//         for (int j = 1; j <= i; j++) {
//             if (j % 2 == 1) {
//                 printf("* ");
//             } else {
//                 printf("# ");
//             }
//         }
//         printf("\n");
//     }

//     return 0;
// }

int main() {
    int taille;
    int i, j;
    
    // Demande la taille du triangle
    printf("Entrez la taille du triangle (inferieure a 10) : ");
    scanf("%d", &taille);

    // Validation de la taille
    if (taille >= 10) {
        printf("La taille doit etre inferieure a 10.\n");
        return 1;
    }

    // Affichage du triangle avec une boucle while
    i = 1;
    while (i <= taille) {
        j = 1;
        while (j <= i) {
            if (j % 2 == 1) {
                printf("* ");
            } else {
                printf("# ");
            }
            j++;
        }
        printf("\n");
        i++;
    }

    return 0;
}

