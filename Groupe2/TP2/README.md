# Réponses aux questions :
# Exercice 2.3
## 1. Exécuter et observer le bytecode :
### Que remarquez-vous dans la sortie du module dis ?
```
On voit comment Python traduit le code source en instructions bas-niveau que l'interpréteur exécute. 
Pour comprendre comment Python optimise le code.
```
## 3. Expérimentation et 4. Réflexion sur l'optimisation :
### Modifiez la fonction calculer_aire en simplifiant l'expression mathématique, par exemple, en remplaçant math.pi * rayon * rayon par une valeur constante. 

### Exécutez à nouveau dis et comparez le bytecode généré. Quelles différences voyez-vous ?
```
En remplaçant math.pi par une constante :

LOAD_CONST 1 (3.14159) : Charge la constante 3.14159 directement.
L'instruction LOAD_GLOBAL pour charger le module math et LOAD_ATTR pour accéder à pi ont été supprimées, ce qui réduit le nombre d'instructions et simplifie le bytecode.
```

## 1. Que fait chaque instruction du bytecode ?
### Par exemple, les instructions comme LOAD_GLOBAL, LOAD_FAST, ou BINARY_MULTIPLY apparaîtront dans le bytecode. Que signifient-elles ?
```
° LOAD_GLOBAL : Cette instruction charge une variable globale (ici math.pi).
° LOAD_FAST : Charge une variable locale, comme rayon.
° BINARY_MULTIPLY : Effectue une multiplication binaire entre deux éléments du sommet de la pile.
° RETURN_VALUE : Retourne la valeur au sommet de la pile d'exécution comme résultat de la fonction.
```

## 2. Modification de l’expression :
### Si vous remplacez l'expression math.pi * rayon * rayon par une valeur constante, quel changement observe-t-on dans le bytecode ? Est-il plus simple ou plus court ?
```
Le bytecode est plus simple et plus court, car il n'y a plus besoin d'accéder à un module externe.
```

## 3. Comment fonctionne la pile d’exécution ?
### Lors de l'analyse du bytecode, observez comment Python utilise une pile pour stocker temporairement les valeurs intermédiaires lors des calculs. 
### Par exemple, les valeurs de rayon et de math.pi sont empilées, puis multipliées.

```
° Stockage Temporaire : La pile d'exécution est utilisée pour stocker temporairement les valeurs pendant le calcul. Par exemple, les valeurs de rayon et de math.pi (ou 3.14159) sont empilées.
° Opérations : Lorsqu'une instruction comme BINARY_MULTIPLY est exécutée, elle multiplie les deux éléments au sommet de la pile et pousse le résultat sur la pile.
° Retour : L'instruction RETURN_VALUE retourne la valeur au sommet de la pile comme résultat de la fonction.
```

# Exemple 2 (somme_dis.py):
## 1. Comment est gérée la boucle for dans le bytecode ?
### Examinez les instructions GET_ITER et FOR_ITER. Que font-elles ?
```
GET_ITER :

Description : Cette instruction obtient un itérateur à partir de l'objet sur le sommet de la pile. Pour une boucle for, l'objet est généralement un range(n) ou une autre séquence.

Exemple dans le bytecode : GET_ITER est utilisé après avoir chargé l'objet range(n) pour préparer l'itérateur pour la boucle.
```

```
FOR_ITER :

Description : Cette instruction récupère le prochain élément de l'itérateur. Si l'itérateur est vide (c'est-à-dire qu'il n'y a plus d'éléments), FOR_ITER saute à l'instruction après la boucle.

Exemple dans le bytecode : FOR_ITER est utilisé pour obtenir le prochain élément à itérer et stocker la valeur dans la variable de boucle (i dans notre exemple). Si aucun élément n'est disponible, il passe à la fin de la boucle.
```

## 2. Structure de la boucle :
### Identifiez les instructions comme SETUP_LOOP et POP_BLOCK. Quel est leur rôle dans la gestion de la boucle ?
```
SETUP_LOOP :

Description : Prépare la gestion de la boucle, y compris la gestion des exceptions comme les interruptions de la boucle (via des break ou des return).

Exemple dans le bytecode : SETUP_LOOP configure le début de la boucle et assure que les instructions après la boucle (en cas de fin prématurée) sont correctement gérées.
```

```
POP_BLOCK :

Description : Marque la fin du bloc de boucle en le retirant de la pile de contrôle. C'est ce qui permet de gérer correctement les fin de boucles et exceptions.

Exemple dans le bytecode : POP_BLOCK est exécuté lorsque la boucle est terminée, pour enlever le bloc de la pile.
```

## 3. Modification de la boucle :
### Comparez les instructions générées pour la boucle while avec celles de la boucle for.

```
Boucle for :

GET_ITER pour obtenir l'itérateur.
FOR_ITER pour obtenir l'élément suivant de l'itérateur.
SETUP_LOOP pour préparer la boucle.
POP_BLOCK pour gérer la fin de la boucle.
```
```
Boucle while :

SETUP_LOOP pour préparer la boucle.
COMPARE_OP pour vérifier la condition de boucle.
POP_JUMP_IF_FALSE pour sauter à la fin si la condition est fausse.
JUMP_ABSOLUTE pour revenir au début de la boucle après chaque itération.
```

#


# Bibliothèques
* 
*

# Références
*
*

# Difficulté
*

# Commentaires
* 
* 

