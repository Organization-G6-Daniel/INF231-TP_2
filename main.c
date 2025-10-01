#include <stdio.h>
#include "tp2.h"

int main() {
    Node* listeSimple = createSampleList();   // Liste simplement chaînée
    DNode* listeDouble = createSampleDoublyList(); // Liste doublement chaînée

    int choix, valeur;
    while (1) {
        printf("\n====== MENU ======\n");
        printf(" Element de la liste : 10, 20, 30, 20, 40, 20, 50 \n");
        printf("1. Supprimer une valeur (liste simplement chaînée)\n");
        printf("2. Insérer dans liste simplement chaînée triée\n");
        printf("3. Insérer dans liste doublement chaînée triée\n");
        printf("4. Afficher la liste simplement chaînée\n");
        printf("5. Afficher la liste doublement chaînée\n");
        printf("6. Quitter\n");
        printf("Votre choix : ");
        scanf("%d", &choix);

        if (choix == 6) {
            printf("Programme terminé.\n");
            break;
        }

        if (choix >= 1 && choix <= 3) {
            printf("Entrez la valeur : ");
            scanf("%d", &valeur);
        }

        switch (choix) {
            case 1:
                printf("Avant suppression : ");
                printList(listeSimple);
                listeSimple = deleteAllOccurrences(listeSimple, valeur);
                printf("Après suppression de %d : ", valeur);
                printList(listeSimple);
                break;

            case 2:
                printf("Avant insertion : ");
                printList(listeSimple);
                listeSimple = insertSorted(listeSimple, valeur);
                printf("Après insertion de %d : ", valeur);
                printList(listeSimple);
                break;

            case 3:
                printf("Avant insertion : ");
                printDoublyList(listeDouble);
                listeDouble = insertSortedDoubly(listeDouble, valeur);
                printf("Après insertion de %d : ", valeur);
                printDoublyList(listeDouble);
                break;

            case 4:
                printf("Liste simplement chaînée : ");
                printList(listeSimple);
                break;

            case 5:
                printf("Liste doublement chaînée : ");
                printDoublyList(listeDouble);
                break;

            default:
                printf("Choix invalide, réessayez.\n");
        }
    }

    // Libération mémoire avant de quitter
    freeList(listeSimple);
    freeDoublyList(listeDouble);

    return 0;
}
