# operateurs.py

# Déclaration des variables
a = 16
b = 3

# Opérations arithmétiques
addition = a + b
soustraction = a - b
multiplication = a * b
division = a / b  # Retourne toujours un float en python
modulo = a % b

# Opérations logiques
egalite = (a == b)
superieur = (a > b)

# Résultats
print(f"Addition : {addition}")
print(f"Soustraction : {soustraction}")
print(f"Multiplication : {multiplication}")
print(f"Division : {division:.2f}")  # Affiche 2 décimales
print(f"Modulo : {modulo}")
print(f"a est égal à b : {'Vrai' if egalite else 'Faux'}")
print(f"a est supérieur à b : {'Vrai' if superieur else 'Faux'}")

#Ici ont peut utiliser des "é" ou "à" sans problème d'affichage