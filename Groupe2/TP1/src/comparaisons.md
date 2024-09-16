# Comparaison entre C et Python

## Bases de la Programmation

### Affichage des Données

**C :**
- Utilise la fonction `printf` pour afficher des données
- Syntaxe : `printf("Format de sortie", variables);`
- Exemple :
  ```c
  #include <stdio.h>
  int main() {
      printf("Bonjour le Monde!\n");
      return 0;
  }
  
**Python :**
- Utilise la fonction `print` pour afficher des données
- Syntaxe : `print("Message")`
- Exemple :
  ```py   
  print("Bonjour le Monde!")

### Gestion de la mémoire

**C :**
- Gestion explicite de la mémoire
- Les variables doivent être déclarées avec un type spécifique

**Python :**
- Gestion automatique de la mémoire
- Les types de variables sont déterminés automatiquement à l'exécution


### Manipulation des variables

**C :**
- Les variables doivent être déclarées avec leur type

**Python :**
- Gestion automatique de la mémoire
- Les types de variables sont déterminés à l'exécution



### Opérateurs logiques 

**C :**
- En C, ce sont des symboles (&&, ||, !)

**Python :**
- En Python, les opérateurs logiques sont des mots-clés (and, or, not)



### Boucles et structures de contrôle

**C :**
- Utilise des accolades {} pour délimiter les blocs de code
- Boucles disponibles : for, while, do...while

**Python :**
- Utilise l'indentation pour délimiter les blocs de code
- Boucles disponibles : for, while



### Conversion et Formatage

**C :**
- Conversion manuelle en binaire en utilisant une boucle pour diviser le nombre par 2 et stocker les restes
- Exemple :
    ```c
    void afficherBinaire(int nombre) {
        int bits[32];
        int index = 0;
        while (nombre > 0) {
            bits[index++] = nombre % 2;
            nombre /= 2;
        }
        for (int i = index - 1; i >= 0; i--) {
            printf("%d", bits[i]);
        }
    }

- En C, il est nécessaire de gérer manuellement la conversion en binaire en utilisant des boucles et des tableaux.

**Python :**
- Utilise des fonctions intégrées et la conversion manuelle
- Exemple :

  ```py   
  def afficher_binaire(nombre):
    if nombre == 0:
        return "0"
    bits = []
    while nombre > 0:
        bits.append(str(nombre % 2))
        nombre //= 2
    return ''.join(bits[::-1])

- Python offre des fonctions intégrées comme bin() pour convertir les nombres en binaire, ce qui simplifie le processus.