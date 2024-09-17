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
            printf("Resultat : %d\n", num1 + num2);
            break;
        case '-':
            printf("Resultat : %d\n", num1 - num2);
            break;
        case '*':
            printf("Resultat : %d\n", num1 * num2);
            break;
        case '/':
            if (num2 != 0) {
                printf("Resultat : %d\n", num1 / num2);
            } else {
                printf("Erreur : Division par zero.\n");
            }
            break;
        case '%':
            if (num2 != 0) {
                printf("Resultat : %d\n", num1 % num2);
            } else {
                printf("Erreur : Division par zero.\n");
            }
            break;
        case '&':
            printf("Resultat : %d\n", num1 & num2);
            break;
        case '|':
            printf("Resultat : %d\n", num1 | num2);
            break;
        case '~':
            printf("Resultat : %d\n", ~num1);
            break;
        default:
            printf("Operateur non reconnu.\n");
            break;
    }

    return 0;
}
