import math
import dis

def calculer_aire(rayon: float) -> float:
    return 3.14159 * rayon * rayon

def main() -> None:
    rayon : float = 5.0
    aire : float = calculer_aire(rayon)
    print(f"L'aire du cercle de rayon {rayon:.2f} est {aire:.2f}")

if __name__ == "__main__":
    # Utilisation de dis pour afficher le bytecode de la fonction
    dis.dis(calculer_aire)
    main()

# Observations sur le bytecode généré :
# LOAD_CONST : Charge la constante 3.14159 directement.
# LOAD_FAST : Charge la variable locale rayon.
# BINARY_MULTIPLY : Multiplie rayon par rayon.
# Retourne le résultat, le bytecode est plus simple car la constante est utilisée.