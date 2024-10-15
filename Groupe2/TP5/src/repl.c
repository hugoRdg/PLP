#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "lexer.h"
#include "parseur.h"
#include "evaluation.h"
#include "postfixe.h"
#include <stdbool.h>
#include "variables.h"

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
    const char *texte = strstr(commande, "echo") ?: strstr(commande, "écho");
    if (texte) {
        texte += 4;
        while (isspace(*texte)) texte++;
        printf("%s\n", texte);
    } else {
        printf("Erreur : texte manquant après echo.\n");
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

// Fonction pour vérifier si l'entrée ressemble à une expression arithmétique
bool est_expression_arithmetique(const char *entree) {
    bool contient_chiffre = false;
    while (*entree) {
        if (isdigit(*entree)) {
            contient_chiffre = true;
        }
        // Vérifie si l'entrée contient des opérateurs ou des parenthèses
        if ((*entree == '+' || *entree == '-' || *entree == '*' || *entree == '/' || 
            *entree == '(' || *entree == ')') && contient_chiffre) {
            return true; // Si on trouve un opérateur et un chiffre, on suppose que c'est une expression
        }
        entree++;
    }
    return false; // Pas une expression arithmétique
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
        {"help", "aide", afficher_aide},
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
        int expression_valide = 0; // Variable pour vérifier si une expression a été évaluée

        // Traite la commande en fonction de son contenu
        for (int i = 0; i < nombre_commandes; i++) {
            if (sont_similaires(commande_lower, commandes[i].nom) || 
                sont_similaires(commande_lower, commandes[i].alias)) {
                commandes[i].fonction(commande);
                commande_trouvee = 1;
                break;
            }
        }

        // Si aucune commande reconnue n'a été trouvée, on vérifie si c'est une expression arithmétique
        if (!commande_trouvee) {
            if (est_expression_arithmetique(commande)) {
                Token *tokens = tokenize(commande);
                if (tokens != NULL) {   
                    char expression_postfixee[1024];
                    infixe_vers_postfixe(tokens, expression_postfixee);
                    
                    if (strlen(expression_postfixee) > 0) {
                        printf("Expression en notation postfixe : %s\n", expression_postfixee);
                        double resultat = evaluer_postfixe(expression_postfixee);
                        printf("Resultat : %.2f\n", resultat);
                        expression_valide = 1;
                    } else {
                        printf("Erreur de syntaxe dans l'expression arithmétique.\n");
                    }

                    free_tokens(tokens);
                } else {
                    printf("Erreur de tokenisation : l'expression ne peut être interprétée.\n");
                }
            } else {
                // Si aucune commande n'a été reconnue et que ce n'est pas une expression arithmétique, on analyse la ligne pour les variables
                analyser_ligne(commande);
                expression_valide = 1; // Considéré comme traité pour éviter un message de commande non reconnue
            }
        }

        // Message d'erreur pour les commandes non reconnues
        if (!commande_trouvee && !expression_valide) {
            printf("Commande non reconnue. Essayez 'echo <texte>' pour afficher du texte, 'aide' ou 'help' pour afficher l'aide, ou 'quitter' ou 'quit' pour quitter.\n");
        }

        printf("\n"); // Saut de ligne après la sortie
    }

    return 0;
}