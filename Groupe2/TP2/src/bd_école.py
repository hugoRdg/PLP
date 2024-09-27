class Etudiant:
    def __init__(self, nom: str, prenom: str, adresse: str, notes: list[float]):
        self.nom = nom
        self.prenom = prenom
        self.adresse = adresse
        self.notes = notes

def main():
    etudiants = []

    # Saisie des informations des étudiants
    for i in range(5):
        print(f"Étudiant {i + 1} :")
        nom = input("Nom : ")
        prenom = input("Prénom : ")
        adresse = input("Adresse : ")
        notes = []
        for j in range(2):
            note = float(input(f"Note {j + 1} : "))
            notes.append(note)
        etudiants.append(Etudiant(nom, prenom, adresse, notes))
        print()

    # Affichage des informations des étudiants
    for i, etudiant in enumerate(etudiants):
        print(f"Étudiant {i + 1} :")
        print(f"Nom : {etudiant.nom}")
        print(f"Prénom : {etudiant.prenom}")
        print(f"Adresse : {etudiant.adresse}")
        print(f"Note 1 : {etudiant.notes[0]:.2f}")
        print(f"Note 2 : {etudiant.notes[1]:.2f}")
        print()

if __name__ == "__main__":
    main()
