// binaire.c

#include <stdio.h>

// Fonction pour afficher la représentation binaire d'un nombre entier
void afficherBinaire(int nombre) {
    // Si le nombre est 0, alors affiche '0'
    if (nombre == 0) {
        printf("0");
        return;
    }

    int bits[32];  // Stocker les bits, assez grand pour un int en C
    int index = 0; //Pour parcourir le tableau

    // Convertis le nombre en binaire en stockant les bits
    while (nombre > 0) {
        // Stocker le bit de poids faible (reste de la division par 2)
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

    // Demande de saisir un nombre entier
    printf("Entrez un nombre entier : ");
    scanf("%d", &nombre);

    printf("Representation binaire : ");
    afficherBinaire(nombre);
    printf("\n");

    return 0;
}
