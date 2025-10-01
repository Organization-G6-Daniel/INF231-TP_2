Cahier de Suivi de Projet Individuel

Projet : Gestion de listes chaînées en C
Nom : ZE ZE FELIX LASKY
UE : TP 2 -INF_231

# I. Travail a Effecute sur le du TP

Implémenter en langage C deux structures de données dynamiques :

Liste simplement chaînée.

Liste doublement chaînée.

Développer les principales opérations sur ces structures : insertion triée, suppression d’occurrences, affichage et libération mémoire.

Mettre en place un programme principal interactif permettant de tester ces opérations via un menu.

# II. Travail effectué

Liste simplement chaînée

Définition de la structure Node avec un entier data et un pointeur next.

Fonctions réalisées sur le TP:

createSampleList() → créer une liste d’exemple.

insertSorted() → insérer un élément en respectant l’ordre croissant.

deleteAllOccurrences() → supprimer toutes les occurrences d’une valeur donnée.

printList() → parcourir et afficher la liste.

freeList() → libérer la mémoire.

Liste doublement chaînée

Définition de la structure DNode avec un entier data et deux pointeurs (prev et next).

Fonctions réalisées :

createSampleDoublyList() → créer une liste d’exemple.

insertSortedDoubly() → insérer un élément dans une liste doublement chaînée triée.

printDoublyList() → parcourir et afficher la liste.

freeDoublyList() → libérer la mémoire.


# III. Algorithmes développés pour le code C . Modulaires 

1 #. Insertion triée dans une liste simplement chaînée

Algorithme InsertSorted(L, x)
Entrée : L (tête de liste), x (valeur à insérer)
Sortie : Nouvelle tête de liste

1. Créer un nouveau nœud N contenant x
2. Si L est vide OU x <= L.data alors
       N.next ← L
       Retourner N
3. Sinon
       P ← L
       Tant que P.next ≠ NULL ET P.next.data < x faire
            P ← P.next
       Fin Tant que
       N.next ← P.next
       P.next ← N
4. Retourner L


# 2. Suppression de toutes les occurrences dans une liste simplement chaînée

Algorithme DeleteAllOccurrences(L, val)
Entrée : L (tête de liste), val (valeur à supprimer)
Sortie : Nouvelle tête de liste

1. Tant que L ≠ NULL ET L.data = val faire
       Supprimer L
       L ← L.next
2. P ← L
3. Tant que P ≠ NULL ET P.next ≠ NULL faire
       Si P.next.data = val alors
            Supprimer P.next
            P.next ← P.next.next
       Sinon
            P ← P.next
4. Retourner L

# 3. Insertion triée dans une liste doublement chaînée

Algorithme InsertSortedDoubly(L, x)
Entrée : L (tête de liste double), x (valeur à insérer)
Sortie : Nouvelle tête de liste

1. Créer un nouveau nœud N contenant x
2. Si L est vide OU x <= L.data alors
       N.next ← L
       Si L ≠ NULL alors L.prev ← N
       Retourner N
3. Sinon
       P ← L
       Tant que P.next ≠ NULL ET P.next.data < x faire
            P ← P.next
       Fin Tant que
       N.next ← P.next
       N.prev ← P
       Si P.next ≠ NULL alors P.next.prev ← N
       P.next ← N
4. Retourner L

V. Difficultés rencontrées / Remarques
-La gestion des pointeurs notamment en début de liste et lors des suppressions multiples 

-l’importance de toujours libérer la mémoire pour éviter les fuites ce montre toujours present 

-Le menu interactif facilite les tests, mais nécessite une saisie correcte des valeurs par l’utilisateur.
