from typing import List
import pdb

def double_values(tableau: List[int]) -> None:
    # Boucle sur chaque élément du tableau
    for compteur in range(len(tableau)):
        
        # Multiplier tous les éléments par 2
        tableau[compteur] *= 2 

        # Déclencher pdb à chaque itération pour observer l'état du tableau et du compteur
        pdb.set_trace()

    return tableau

# Créer un tableau d'exemple
tableau: List[int] = [1, 2, 3, 4, 5]

# Appeler la fonction et stocker le résultat
resultat = double_values(tableau)

# Afficher le résultat final
print(resultat)

