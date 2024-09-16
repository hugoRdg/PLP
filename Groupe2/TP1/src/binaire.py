def afficher_binaire(nombre):
    if nombre == 0:
        return "0"
    
    bits = []
    
    while nombre > 0:
        bits.append(str(nombre % 2))
        nombre //= 2
    
    # Afficher les bits dans le bon ordre
    return ''.join(bits[::-1])

def main():
    nombre = int(input("Entrez un nombre entier : "))
    binaire = afficher_binaire(nombre)
    print(f"Représentation binaire : {binaire}")

if __name__ == "__main__":
    main()
