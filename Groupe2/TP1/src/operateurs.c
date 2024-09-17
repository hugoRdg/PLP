// operateurs.c

#include <stdio.h>

int main() {
    int a = 16;
    int b = 3;
    float division_result;  // Stocker le résultat de la division

    // Opérations arithmétiques
    int addition = a + b;
    int soustraction = a - b;
    int multiplication = a * b;
    division_result = (float)a / b;  // Pour obtenir un résultat flottant
    int modulo = a % b;

    // Opérations logiques
    int egalite = (a == b);
    int superieur = (a > b);

    // Résultats
    printf("Addition : %d\n", addition);
    printf("Soustraction : %d\n", soustraction);
    printf("Multiplication : %d\n", multiplication);
    printf("Division : %.2f\n", division_result);
    printf("Modulo : %d\n", modulo);
    printf("a est egal a b : %s\n", egalite ? "Vrai" : "Faux");
    printf("a est superieur a b : %s\n", superieur ? "Vrai" : "Faux");

    return 0;
}
