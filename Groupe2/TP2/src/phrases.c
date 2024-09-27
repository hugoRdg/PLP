#include <stdio.h>
#include <string.h>

#define MAX_LINE 1024

// Fonction pour compter les occurrences
int compter_occurrences(const char *ligne, const char *phrase) {
    int count = 0;
    const char *tmp = ligne;

    while ((tmp = strstr(tmp, phrase)) != NULL) {
        count++;
        tmp += strlen(phrase);  // Avance après la phrase trouvée
    }

    return count;
}

int main() {
    char fichier[256];
    char phrase[256];
    char ligne[MAX_LINE];
    FILE *fp;
    int ligne_num = 0;

    // Nom du fichier
    printf("Entrez le nom du fichier : ");
    fgets(fichier, sizeof(fichier), stdin);
    fichier[strcspn(fichier, "\n")] = '\0';  // Enlever le \n

    // Phrase à rechercher
    printf("Entrez la phrase a rechercher : ");
    fgets(phrase, sizeof(phrase), stdin);
    phrase[strcspn(phrase, "\n")] = '\0';

    // Ouverture du fichier
    fp = fopen(fichier, "r");
    if (fp == NULL) {
        printf("Erreur d'ouverture du fichier.\n");
        return 1;
    }

    // Lecture du fichier
    while (fgets(ligne, sizeof(ligne), fp) != NULL) {
        ligne_num++;
        int occurrences = compter_occurrences(ligne, phrase);
        if (occurrences > 0) {
            printf("Ligne %d, %d fois\n", ligne_num, occurrences);
        }
    }

    // Fermeture du fichier
    fclose(fp);
    return 0;
}
