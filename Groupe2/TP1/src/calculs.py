# calcul.py

def main():
    num1 = int(input("Entrez le premier nombre : "))
    num2 = int(input("Entrez le second nombre : "))
    op = input("Entrez l'opérateur (+, -, *, /, %, &, |, ~) : ")

    match op:
        case '+':
            print(f"Résultat : {num1 + num2}")
        case '-':
            print(f"Résultat : {num1 - num2}")
        case '*':
            print(f"Résultat : {num1 * num2}")
        case '/':
            if num2 != 0:
                print(f"Résultat : {num1 / num2}")
            else:
                print("Erreur : Division par zéro.")
        case '%':
            if num2 != 0:
                print(f"Résultat : {num1 % num2}")
            else:
                print("Erreur : Division par zéro.")
        case '&':
            print(f"Résultat : {num1 & num2}")
        case '|':
            print(f"Résultat : {num1 | num2}")
        case '~':
            print(f"Résultat : {~num1}")
        case _:
            print("Opérateur non reconnu.")

# Cette condition vérifie si le script est exécuté directement plutôt qu'importé comme module
if __name__ == "__main__":
    main()
