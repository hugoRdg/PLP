#include <stdio.h>
#include <limits.h>
#include <float.h>

int main() {
    // Déclaration et initialisation des variables
    char c = 'A';
    signed char sc = -100;
    unsigned char uc = 200;
    short s = -30000;
    unsigned short us = 600;
    int i = -214;
    unsigned int ui = 42949U;
    long int li = -214748L;
    unsigned long int uli = 4294UL;
    long long int lli = -92233720LL;
    float f = 3.14F;
    double d = 2.7182;
    long double ld = 1.61803L;

    // Affichage des valeurs
    printf("char : %c\n", c);
    printf("signed char : %d\n", sc);
    printf("unsigned char : %u\n", uc);
    printf("short : %d\n", s);
    printf("unsigned short : %u\n", us);
    printf("int : %d\n", i);
    printf("unsigned int : %u\n", ui);
    printf("long int : %ld\n", li);
    printf("unsigned long int : %lu\n", uli);
    printf("long long int : %lld\n", lli);
    printf("float : %.2f\n", f);
    printf("double : %.15f\n", d);
    printf("long double : %.18Lf\n", ld);

    return 0;
}