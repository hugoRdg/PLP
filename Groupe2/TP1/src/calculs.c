// calculs.c

#include <stdio.h>
#include <limits.h>

int main() {
    int num1, num2;
    char op;

    // Demande d'entrer les valeurs
    printf("Entrez le premier nombre : ");
    scanf("%d", &num1);
    printf("Entrez le second nombre : ");
    scanf("%d", &num2);
    printf("Entrez l'operateur (+, -, *, /, %, &, |, ~) : ");
    scanf(" %c", &op);

    switch (op) {
        case '+':
            // Addition
            printf("Resultat : %d\n", num1 + num2);
            break;
        case '-':
            // Soustraction
            printf("Resultat : %d\n", num1 - num2);
            break;
        case '*':
            // Multiplication
            printf("Resultat : %d\n", num1 * num2);
            break;
        case '/':
            // Division avec vérification si le second nombre n'est pas zéro pour éviter la division par zéro
            if (num2 != 0) {
                printf("Resultat : %d\n", num1 / num2);
            } else {
                printf("Erreur : Division par zero.\n");
            }
            break;
        case '%':
            // Modulo (reste de la division entière) avec vérification de division par zéro
            if (num2 != 0) {
                printf("Resultat : %d\n", num1 % num2);
            } else {
                printf("Erreur : Division par zero.\n");
            }
            break;
        case '&':
            // Opérateur AND bit à bit
            printf("Resultat : %d\n", num1 & num2);
            break;
        case '|':
            // Opérateur OR bit à bit
            printf("Resultat : %d\n", num1 | num2);
            break;
        case '~':
            // Opérateur NOT bit à bit
            printf("Resultat : %d\n", ~num1);
            break;
        default:
            // Message d'erreur si l'utilisateur entre un opérateur non reconnu
            printf("Operateur non reconnu.\n");
            break;
    }

    return 0;
}
