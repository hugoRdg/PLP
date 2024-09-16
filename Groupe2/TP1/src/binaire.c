#include <stdio.h>

void afficherBinaire(int nombre) {
    if (nombre == 0) {
        printf("0");
        return;
    }

    int bits[32];  // Stocker les bits, assez grand pour un int en C
    int index = 0;

    // Convertis le nombre en binaire en stockant les bits
    while (nombre > 0) {
        bits[index++] = nombre % 2;
        nombre /= 2;
    }

    // Afficher les bits dans le bon ordre
    for (int i = index - 1; i >= 0; i--) {
        printf("%d", bits[i]);
    }
}

int main() {
    int nombre;

    printf("Entrez un nombre entier : ");
    scanf("%d", &nombre);

    printf("Representation binaire : ");
    afficherBinaire(nombre);
    printf("\n");

    return 0;
}
