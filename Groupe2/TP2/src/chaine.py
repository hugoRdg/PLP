def longueur_chaine(chaine: str) -> int:
    # Calculer la longueur d'une chaîne.
    longueur = 0
    for _ in chaine:
        longueur += 1
    return longueur

def copier_chaine(source: str) -> str:
    # Copier une chaîne dans une nouvelle chaîne.
    return source

def concatener_chaines(chaine1: str, chaine2: str) -> str:
    # Concaténer deux chaînes.
    return chaine1 + chaine2

def main() -> None:
    chaine1 = input("Entrez la première chaîne : ")
    chaine2 = input("Entrez la deuxième chaîne : ")

    # Calculer la longueur des chaînes
    print(f"Longueur de la première chaîne : {longueur_chaine(chaine1)}")
    print(f"Longueur de la deuxième chaîne : {longueur_chaine(chaine2)}")

    # Copier la première chaîne dans une nouvelle chaîne
    copie = copier_chaine(chaine1)
    print(f"Après copie, résultat : {copie}")

    # Concaténer les deux chaînes
    resultat = concatener_chaines(chaine1, chaine2)
    print(f"Après concaténation, résultat : {resultat}")

if __name__ == "__main__":
    main()
