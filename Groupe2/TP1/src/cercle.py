import math

# Demander de saisis du rayon
rayon = float(input("Entrez le rayon du cercle : "))

# Calcule de l'aire et du périmètre
aire = math.pi * rayon * rayon
perimetre = 2 * math.pi * rayon

# Résultats
print(f"Aire du cercle : {aire:.2f}")
print(f"Périmètre du cercle : {perimetre:.2f}")
