def compter_occurrences(ligne, phrase):
    """Compter les occurrences d'une phrase dans une ligne."""
    return ligne.count(phrase)

def main():
    # Demande du nom du fichier
    fichier = input("Entrez le nom du fichier : ")

    # Demande de la phrase à rechercher
    phrase = input("Entrez la phrase à rechercher : ")

    # Ouverture et lecture du fichier
    try:
        with open(fichier, 'r', encoding='utf-8') as f:
            lignes = f.readlines()

        # Parcours des lignes et recherche de la phrase
        for i, ligne in enumerate(lignes, start=1):
            occurrences = compter_occurrences(ligne, phrase)
            if occurrences > 0:
                print(f"Ligne {i}, {occurrences} fois")
    except FileNotFoundError:
        print(f"Le fichier {fichier} n'existe pas.")

if __name__ == "__main__":
    main()
