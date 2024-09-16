#include <stdio.h>

int main() {
    // Divisibilité par 4 mais pas par 6
    printf("Nombres de 1 a 1000 divisibles par 4 mais pas par 6 :\n");
    for (int i = 1; i <= 1000; i++) {
        if (i % 4 == 0 && i % 6 != 0) {
            printf("%d\n", i);
        }
    }

    printf("\n");

    // Nombres pairs et divisibles par 8
    printf("Nombres de 1 a 1000 pairs et divisibles par 8 :\n");
    for (int i = 1; i <= 1000; i++) {
        if (i % 2 == 0 && i % 8 == 0) {
            printf("%d\n", i);
        }
    }

    printf("\n");

    // Divisibilité par 5 ou 7 mais pas par 10
    printf("Nombres de 1 a 1000 divisibles par 5 ou 7 mais pas par 10 :\n");
    for (int i = 1; i <= 1000; i++) {
        if ((i % 5 == 0 || i % 7 == 0) && i % 10 != 0) {
            printf("%d\n", i);
        }
    }

    return 0;
}
