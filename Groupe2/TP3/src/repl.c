#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// Version de l'interpréteur
#define VERSION "1.0.0"

// Structure pour stocker les commandes
typedef struct {
    const char *nom; // Nom de la commande
    const char *alias; // Alias de la commande (version française ou anglaise)
    void (*fonction)(const char *); // Pointeur vers la fonction associée
} Commande;

// Fonction qui affiche la version de l'interpréteur
void afficher_version() {
    printf("Interpreteur de commandes : Version %s\n", VERSION);
}

// Fonction qui affiche les commandes disponibles
void afficher_aide(const char *commande) {
    printf("Commandes disponibles :\n");
    printf("  echo <texte> : Affiche le texte fourni.\n");
    printf("  date : Affiche la date actuelle.\n");
    printf("  version : Affiche la version de l'interpréteur.\n");
    printf("  quitter / quit : Quitte le programme.\n");
    printf("  aide / help : Affiche cette aide.\n");
}

// Fonction pour traiter la commande echo
void traiter_echo(const char *commande) {
    printf("Écho : ");
    const char *texte = strstr(commande, "echo");
    if (texte == NULL) {
        texte = strstr(commande, "écho");
    }
    if (texte != NULL) {
        texte += 4; // Saute "echo" ou "écho"
        while (isspace(*texte)) texte++; // Saute les espaces
        printf("%s\n", texte);
    } else {
        printf("Erreur : texte manquant après la commande echo/écho.\n");
    }
}

// Fonction pour quitter l'interpreteur
void traiter_quit(const char *commande){
    printf("Arret...\n");
    exit(0);
}

// Fonction pour récupérer la date actuelle
void traiter_date(const char *commande){
    system("date");
}

// Fonction pour convertir une chaîne en minuscules
void to_lower(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower((unsigned char)str[i]);
    }
}

// Fonction pour vérifier si deux chaînes sont similaires
int sont_similaires(const char *str1, const char *str2) {
    // Calcule la longueur des deux chaînes
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    
    // Si la différence de longueur est supérieure à 2, les chaînes sont considérées comme trop différentes
    if (abs(len1 - len2) > 2) return 0;

    int diff = 0;  // Compteur de différences entre les chaînes
    int i = 0, j = 0;  // Indices pour parcourir str1 et str2 respectivement
    
    // Parcourt les deux chaînes simultanément
    while (i < len1 && j < len2) {
        // Compare les caractères en les convertissant en minuscules
        if (tolower((unsigned char)str1[i]) != tolower((unsigned char)str2[j])) {
            diff++; 
            
            if (diff > 2) return 0; // Trop de différences
            
            // Gestion des différences de longueur ou des caractères insérés/supprimés
            if (len1 > len2) i++;  // str1 plus longue, on avance dans str1
            else if (len2 > len1) j++;  // str2 plus longue, on avance dans str2
            else {
                // Même longueur, on avance dans les deux chaînes
                i++;
                j++;
            }
        } else {
            // Les caractères sont identiques, on avance dans les deux chaînes
            i++;
            j++;
        }
    }

    return 1;
}

/**
 * Programme qui simule un interpréteur de commandes simple.
 * Il lit les commandes utilisateur et les traite en fonction de leur contenu.
 */
int main()
{
    int continuer = 1; // Variable pour contrôler la boucle principale

    // Déclaration du tableau de commandes
    Commande commandes[] = {
        {"echo", "écho", traiter_echo},
        {"date", "date", traiter_date},
        {"version", "version", afficher_version},
        {"quit", "quitter", traiter_quit},
        {"help", "aide", afficher_aide}
    };

    int nombre_commandes = sizeof(commandes) / sizeof(commandes[0]);

    // Boucle principale qui lit et traite les commandes utilisateur
    while (1)
    {
        printf("> "); // Affiche le prompt de commande

        // Buffer pour stocker la commande utilisateur
        char commande[1024];

        // Lit la commande utilisateur et la stocke dans le buffer
        fgets(commande, sizeof(commande), stdin);

        // Enlève le caractère de fin de ligne ajouté par fgets
        commande[strcspn(commande, "\n")] = 0;
        
        char commande_lower[1024];
        strcpy(commande_lower, commande);
        to_lower(commande_lower);   

        int commande_trouvee = 0; // Variable pour vérifier si la commande a été trouvée

        // Traite la commande en fonction de son contenu
        for (int i = 0; i < nombre_commandes; i++) {
            if (sont_similaires(commande_lower, commandes[i].nom) || 
                sont_similaires(commande_lower, commandes[i].alias)) {
                commandes[i].fonction(commande);
                commande_trouvee = 1;
                break;
            }
        }

        if (!commande_trouvee) {
            // Affiche un message d'erreur si la commande est inconnue
            printf("Commande non reconnue. Essayez 'echo <texte>' pour afficher du texte, 'aide' ou 'help' pour afficher l'aide, ou 'quitter' ou 'quit' pour quitter.\n");
        }

        printf("\n"); // Saut de ligne après la sortie
    }

    return 0;
}
