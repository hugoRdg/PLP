#include <stdio.h>
#include <stdbool.h>

#define MAX_COULEURS 100

// Structure pour représenter une couleur
typedef struct {
    unsigned char r;
    unsigned char g;
    unsigned char b;
    unsigned char a;
} Couleur;

// Structure pour stocker une couleur distincte et son nombre d'occurrences
typedef struct {
    Couleur couleur;
    int occurrences;
} CouleurDistincte;

// Fonction pour comparer deux couleurs
bool comparer_couleurs(Couleur c1, Couleur c2) {
    return c1.r == c2.r && c1.g == c2.g && c1.b == c2.b && c1.a == c2.a;
}

// Fonction pour trouver ou ajouter une couleur distincte
int trouver_ou_ajouter_couleur(CouleurDistincte distinctes[], int *taille, Couleur couleur) {
    for (int i = 0; i < *taille; i++) {
        if (comparer_couleurs(distinctes[i].couleur, couleur)) {
            return i;
        }
    }
    distinctes[*taille].couleur = couleur;
    distinctes[*taille].occurrences = 0;
    (*taille)++;
    return *taille - 1;
}

int main() {
    Couleur couleurs[MAX_COULEURS] = {
        {0xFF, 0x23, 0x23, 0x45}, {0xFF, 0x00, 0x23, 0x12}, {0xFF, 0x23, 0x23, 0x45}
    };

    CouleurDistincte distinctes[MAX_COULEURS];
    int taille_distinctes = 0;

    // Parcours du tableau de couleurs et compte les occurrences
    for (int i = 0; i < 3; i++) { // Ici on limite à 3 couleurs en exemple
        int index = trouver_ou_ajouter_couleur(distinctes, &taille_distinctes, couleurs[i]);
        distinctes[index].occurrences++;
    }

    // Affichage des couleurs distinctes et de leurs occurrences
    printf("Couleurs distinctes et leurs occurrences :\n");
    for (int i = 0; i < taille_distinctes; i++) {
        printf("%02x 0x%02x 0x%02x 0x%02x : %d\n",
               distinctes[i].couleur.r, distinctes[i].couleur.g, distinctes[i].couleur.b, distinctes[i].couleur.a, distinctes[i].occurrences);
    }

    return 0;
}
