class Couleur:
    def __init__(self, r, g, b, a):
        self.r = r
        self.g = g
        self.b = b
        self.a = a

    def __eq__(self, other):
        return (self.r, self.g, self.b, self.a) == (other.r, other.g, other.b, other.a)

    def __hash__(self):
        return hash((self.r, self.g, self.b, self.a))

    def __repr__(self):
        return f"{self.r:02x} 0x{self.g:02x} 0x{self.b:02x} 0x{self.a:02x}"

# Tableau de couleurs
couleurs = [
    Couleur(0xFF, 0x23, 0x23, 0x45),
    Couleur(0xFF, 0x00, 0x23, 0x12),
    Couleur(0xFF, 0x23, 0x23, 0x45)
]

# Dictionnaire pour stocker les couleurs distinctes et leur nombre d'occurrences
occurrences = {}

# Comptage des occurrences
for couleur in couleurs:
    if couleur in occurrences:
        occurrences[couleur] += 1
    else:
        occurrences[couleur] = 1

# Affichage des couleurs distinctes et de leurs occurrences
print("Couleurs distinctes et leurs occurrences :")
for couleur, count in occurrences.items():
    print(f"{couleur} : {count}")
