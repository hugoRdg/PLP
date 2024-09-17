#include <stdio.h>

// Fonction pour calculer la longueur d'une chaîne
int longueur_chaine(const char *chaine) {
    int longueur = 0;
    while (chaine[longueur] != '\0') {
        longueur++;
    }
    return longueur;
}

// Fonction pour copier une chaîne dans une autre
void copier_chaine(char *destination, const char *source) {
    int i = 0;
    while (source[i] != '\0') {
        destination[i] = source[i];
        i++;
    }
    destination[i] = '\0'; 
}

// Fonction pour concaténer deux chaînes
void concatener_chaines(char *destination, const char *source) {
    int i = 0;
    while (destination[i] != '\0') {
        i++;
    }
    int j = 0;
    while (source[j] != '\0') {
        destination[i] = source[j];
        i++;
        j++;
    }
    destination[i] = '\0';
}

int main() {
    char chaine1[100], chaine2[100];
    char result[200];

    // Demande des chaînes à l'utilisateur
    printf("Entrez la première chaîne : ");
    fgets(chaine1, sizeof(chaine1), stdin);
    printf("Entrez la deuxième chaîne : ");
    fgets(chaine2, sizeof(chaine2), stdin);

    // Enleve le caractère de nouvelle ligne s'il est présent
    chaine1[strcspn(chaine1, "\n")] = '\0';
    chaine2[strcspn(chaine2, "\n")] = '\0';

    // Calculer la longueur des chaînes
    printf("Longueur de la première chaîne : %d\n", longueur_chaine(chaine1));
    printf("Longueur de la deuxième chaîne : %d\n", longueur_chaine(chaine2));

    // Copier la première chaîne dans la deuxième chaîne
    copier_chaine(result, chaine1);
    printf("Après copie, résultat : %s\n", result);

    // Concaténer les deux chaînes
    concatener_chaines(result, chaine2);
    printf("Après concaténation, résultat : %s\n", result);

    return 0;
}
