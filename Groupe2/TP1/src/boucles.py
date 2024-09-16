# Demande la taille du triangle
# taille = int(input("Entrez la taille du triangle (inférieure à 10) : "))

# # Validation de la taille
# if taille >= 10:
#     print("La taille doit être inférieure à 10.")
# else:
#     # Affichage du triangle avec des boucles for
#     for i in range(1, taille + 1):
#         for j in range(1, i + 1):
#             if j % 2 == 1:
#                 print("*", end=" ")
#             else:
#                 print("#", end=" ")
#         print()

# Demande la taille du triangle
taille = int(input("Entrez la taille du triangle (inférieure à 10) : "))

# Validation de la taille
if taille >= 10:
    print("La taille doit être inférieure à 10.")
else:
    # Affichage du triangle avec une boucle while
    i = 1
    while i <= taille:
        j = 1
        while j <= i:
            if j % 2 == 1:
                print("*", end=" ")
            else:
                print("#", end=" ")
            j += 1
        print()
        i += 1
