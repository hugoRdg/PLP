#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Version de l'interpréteur
#define VERSION "1.0.0"

// Structure pour stocker les commandes
typedef struct {
    const char *nom; // Nom de la commande
    void (*fonction)(const char *); // Pointeur vers la fonction associée
} Commande;

// Fonction qui affiche la version de l'interpréteur
void afficher_version() {
    printf("Interpreteur de commandes : Version %s\n", VERSION);
}

// Fonction qui affiche les commandes disponibles
void afficher_aide() {
    printf("Commandes disponibles :\n");
    printf("  echo <text> : Affiche le texte fourni.\n");
    printf("  date : Affiche la date actuelle.\n");
    printf("  version : Affiche la version de l'interpréteur.\n");
    printf("  quit : Quitte le programme.\n");
    printf("  help : Affiche cette aide.\n");
}

// Fonction pour traiter la commande echo
void traiter_echo(const char *commande) {
    // Traite la commande "echo" pour afficher du texte
    printf("Echo: ");

    // Imprime la chaîne
    for (int i = 5; commande[i] != '\0'; i++)
    {
        printf("%c", commande[i]);
    }
    printf("\n"); // Saut de ligne après la sortie
}

// Fonction pour quitter l'interpreteur
void traiter_quit(){
    // Quitte le programme si la commande est "quit"
    printf("Arret...\n");
}

// Fonction pour récupérer la date actuelle
void traiter_date(const char *commande){
    // Affiche la date si la commande est "date"
    system("date");
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
        {"echo", traiter_echo},
        {"date", traiter_date},
        {"version", afficher_version},
        {"quit", traiter_quit},
        {"help", afficher_aide}
    };

    int nombre_commandes = sizeof(commandes) / sizeof(commandes[0]);

    // Boucle principale qui lit et traite les commandes utilisateur
    while (continuer)
    {
        printf("> "); // Affiche le prompt de commande

        // Buffer pour stocker la commande utilisateur
        char commande[1024];

        // Lit la commande utilisateur et la stocke dans le buffer
        fgets(commande, sizeof(commande), stdin);

        // Enlève le caractère de fin de ligne ajouté par fgets
        commande[strcspn(commande, "\n")] = 0;

        int commande_trouvee = 0; // Variable pour vérifier si la commande a été trouvée

        // Traite la commande en fonction de son contenu
        for (int i = 0; i < nombre_commandes; i++) {
            if (strncmp(commande, commandes[i].nom, strlen(commandes[i].nom)) == 0) {
                commandes[i].fonction(commande); // Appelle la fonction associée
                commande_trouvee = 1;
                break;
            }
        }

        // Si la commande est "quit", on sort de la boucle
        if (commande_trouvee && strcmp(commande, "quit") == 0) {
            continuer = 0; // Met fin à la boucle
        }

        if (!commande_trouvee) {
            // Affiche un message d'erreur si la commande est inconnue
            printf("Commande non reconnue. Essayez 'echo <text>' pour afficher du texte, ou tapez 'quit' pour quitter.\n");
        }

        printf("\n"); // Saut de ligne après la sortie
    }

    return 0;
}
