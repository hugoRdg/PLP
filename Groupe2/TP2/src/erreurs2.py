from typing import List

def double_values(tableau: List[int]) -> None:
    # Boucle sur chaque élément du tableau
    for compteur in range(len(tableau)):
        # Introduire une erreur : multiplier par 3 les éléments impairs, par 2 les pairs
        if compteur % 2 == 0:
            tableau[compteur] *= 2  # Multiplier les éléments d'indice pair par 2
        else:
            tableau[compteur] *= 3  # Multiplier les éléments d'indice impair par 3

    return tableau

# Créer un tableau d'exemple
tableau: List[int] = [1, 2, 3, 4, 5]

# Appeler la fonction et stocker le résultat
resultat = double_values(tableau)

# Afficher le résultat final
print(resultat)
