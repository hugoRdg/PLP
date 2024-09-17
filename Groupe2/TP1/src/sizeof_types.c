// sizeof_types.c

#include <stdio.h>

int main() {
    printf("Taille des types de base en C :\n");

    printf("char : %zu octets\n", sizeof(char));
    printf("short : %zu octets\n", sizeof(short));
    printf("int : %zu octets\n", sizeof(int));
    printf("long int : %zu octets\n", sizeof(long int));
    printf("long long int : %zu octets\n", sizeof(long long int));
    printf("float : %zu octets\n", sizeof(float));
    printf("double : %zu octets\n", sizeof(double));
    printf("long double : %zu octets\n", sizeof(long double));

    // Types signés et non-signés
    printf("\nTypes signés et non-signés :\n");

    printf("signed char : %zu octets\n", sizeof(signed char));
    printf("unsigned char : %zu octets\n", sizeof(unsigned char));
    printf("signed short : %zu octets\n", sizeof(signed short));
    printf("unsigned short : %zu octets\n", sizeof(unsigned short));
    printf("signed int : %zu octets\n", sizeof(signed int));
    printf("unsigned int : %zu octets\n", sizeof(unsigned int));
    printf("signed long int : %zu octets\n", sizeof(signed long int));
    printf("unsigned long int : %zu octets\n", sizeof(unsigned long int));

    return 0;
}
