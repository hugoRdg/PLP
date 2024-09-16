#include <stdio.h>
#define PI 3.14159

int main() {
    float rayon;
    float aire, perimetre;

    // Demander de saisis du rayon
    printf("Entrez le rayon du cercle : ");
    scanf("%f", &rayon);

    // Calcule de l'aire et du périmètre
    aire = PI * rayon * rayon;
    perimetre = 2 * PI * rayon;

    // Résultats
    printf("Aire du cercle : %.2f\n", aire);
    printf("Périmètre du cercle : %.2f\n", perimetre);

    return 0;
}
