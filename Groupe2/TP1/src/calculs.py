# calcul.py

def main():
    num1 = int(input("Entrez le premier nombre : "))
    num2 = int(input("Entrez le second nombre : "))
    op = input("Entrez l'opérateur (+, -, *, /, %, &, |, ~) : ")

    match op:
        case '+':
            # Addition
            print(f"Résultat : {num1 + num2}")
        case '-':
            # Soustraction
            print(f"Résultat : {num1 - num2}")
        case '*':
            # Multiplication
            print(f"Résultat : {num1 * num2}")
        case '/':
            # Division avec gestion de la division par zéro
            if num2 != 0:
                print(f"Résultat : {num1 / num2}")
            else:
                print("Erreur : Division par zéro.")
        case '%':
            # Modulo avec gestion de la division par zéro
            if num2 != 0:
                print(f"Résultat : {num1 % num2}")
            else:
                print("Erreur : Division par zéro.")
        case '&':
            # Opérateur AND bit à bit
            print(f"Résultat : {num1 & num2}")
        case '|':
            # Opérateur OR bit à bit
            print(f"Résultat : {num1 | num2}")
        case '~':
            # Opérateur NOT bit à bit
            print(f"Résultat : {~num1}")
        case _:
            # Cas par défaut si l'opérateur n'est pas reconnu
            print("Opérateur non reconnu.")

# Cette condition vérifie si le script est exécuté directement plutôt qu'importé comme module
if __name__ == "__main__":
    main()
