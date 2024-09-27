#include <stdio.h>
#include <string.h>

// Définition de la structure pour un étudiant
struct Etudiant {
    char nom[50];
    char prenom[50];
    char adresse[100];
    float notes[2];
};

int main() {
    struct Etudiant etudiants[5];
    int i, j;

    // Saisie des informations des étudiants
    for (i = 0; i < 5; i++) {
        printf("Etudiant %d :\n", i + 1);
        printf("Nom : ");
        fgets(etudiants[i].nom, sizeof(etudiants[i].nom), stdin);
        etudiants[i].nom[strcspn(etudiants[i].nom, "\n")] = '\0';  // Enlever '\n'

        printf("Prenom : ");
        fgets(etudiants[i].prenom, sizeof(etudiants[i].prenom), stdin);
        etudiants[i].prenom[strcspn(etudiants[i].prenom, "\n")] = '\0';

        printf("Adresse : ");
        fgets(etudiants[i].adresse, sizeof(etudiants[i].adresse), stdin);
        etudiants[i].adresse[strcspn(etudiants[i].adresse, "\n")] = '\0';

        for (j = 0; j < 2; j++) {
            printf("Note %d : ", j + 1);
            scanf("%f", &etudiants[i].notes[j]);
        }
        getchar();  // Nettoyer le buffer après scanf
        printf("\n");
    }

    // Affichage des informations des étudiants
    for (i = 0; i < 5; i++) {
        printf("Etudiant %d :\n", i + 1);
        printf("Nom : %s\n", etudiants[i].nom);
        printf("Prenom : %s\n", etudiants[i].prenom);
        printf("Adresse : %s\n", etudiants[i].adresse);
        printf("Note 1 : %.2f\n", etudiants[i].notes[0]);
        printf("Note 2 : %.2f\n", etudiants[i].notes[1]);
        printf("\n");
    }

    return 0;
}