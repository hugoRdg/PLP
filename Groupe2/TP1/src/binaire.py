# binaire.py

def afficher_binaire(nombre):
    if nombre == 0:
        return "0"
    
    bits = []
    
    # Boucle pour convertir le nombre en binaire
    while nombre > 0:
        # Ajouter le bit de poids faible (reste de la division par 2) à la liste
        bits.append(str(nombre % 2))
        nombre //= 2
    
    # Afficher les bits dans le bon ordre
    return ''.join(bits[::-1])

def main():
    nombre = int(input("Entrez un nombre entier : "))
    binaire = afficher_binaire(nombre)
    print(f"Représentation binaire : {binaire}")

# Cette condition vérifie si le script est exécuté directement plutôt qu'importé comme module
if __name__ == "__main__":
    main()
