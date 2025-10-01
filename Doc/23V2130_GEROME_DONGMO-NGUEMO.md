Programme Modulaire TP2 - Structures de Données

 Structure du Projet

tp2_project/
├── tp2.h          // Interface du module
├── tp2.c          // Implémentation du module
└── main.c         // Programme principal

 Fichiers Source

 tp2.h

#ifndef TP2_H
#define TP2_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Structure pour liste simplement chaînée
typedef struct NodeS {
    int data;
    struct NodeS* next;
} NodeS;

// Structure pour liste doublement chaînée
typedef struct NodeD {
    int data;
    struct NodeD* next;
    struct NodeD* prev;
} NodeD;

// Prototypes des fonctions

// 1. Suppression de toutes les occurrences
NodeS* supprimerOccurrences(NodeS* head, int valeur);

// 2. Insertion dans liste simplement chaînée triée
NodeS* insererListeSimpleTrie(NodeS* head, int valeur);

// 3. Insertion dans liste doublement chaînée triée
NodeD* insererListeDoubleTrie(NodeD* head, int valeur);

// 4. Listes simplement chaînées circulaires
NodeS* insererTeteCirculaireSimple(NodeS* head, int valeur);
NodeS* insererQueueCirculaireSimple(NodeS* head, int valeur);

// 5. Listes doublement chaînées circulaires
NodeD* insererTeteCirculaireDouble(NodeD* head, int valeur);
NodeD* insererQueueCirculaireDouble(NodeD* head, int valeur);

// Fonctions utilitaires
void afficherListeSimple(NodeS* head);
void afficherListeDouble(NodeD* head);
void afficherListeCirculaireSimple(NodeS* head);
void afficherListeCirculaireDouble(NodeD* head);
void libererListeSimple(NodeS* head);
void libererListeDouble(NodeD* head);

#endif

 tp2.c

#include "tp2.h"

// 1. Supprimer toutes les occurrences d'un élément
NodeS* supprimerOccurrences(NodeS* head, int valeur) {
    NodeS* courant = head;
    NodeS* precedent = NULL;
    NodeS* aSupprimer;
    
    while (courant != NULL) {
        if (courant->data == valeur) {
            aSupprimer = courant;
            
            if (precedent == NULL) {
                // Suppression en tête
                head = courant->next;
            } else {
                precedent->next = courant->next;
            }
            
            courant = courant->next;
            free(aSupprimer);
        } else {
            precedent = courant;
            courant = courant->next;
        }
    }
    
    return head;
}

// 2. Insertion dans liste simplement chaînée triée
NodeS* insererListeSimpleTrie(NodeS* head, int valeur) {
    NodeS* nouveau = (NodeS*)malloc(sizeof(NodeS));
    nouveau->data = valeur;
    nouveau->next = NULL;
    
    // Cas liste vide ou insertion en tête
    if (head == NULL || valeur < head->data) {
        nouveau->next = head;
        return nouveau;
    }
    
    // Recherche de la position d'insertion
    NodeS* courant = head;
    while (courant->next != NULL && courant->next->data < valeur) {
        courant = courant->next;
    }
    
    // Insertion
    nouveau->next = courant->next;
    courant->next = nouveau;
    
    return head;
}

// 3. Insertion dans liste doublement chaînée triée
NodeD* insererListeDoubleTrie(NodeD* head, int valeur) {
    NodeD* nouveau = (NodeD*)malloc(sizeof(NodeD));
    nouveau->data = valeur;
    nouveau->next = NULL;
    nouveau->prev = NULL;
    
    // Cas liste vide
    if (head == NULL) {
        return nouveau;
    }
    
    // Cas insertion en tête
    if (valeur < head->data) {
        nouveau->next = head;
        head->prev = nouveau;
        return nouveau;
    }
    
    // Recherche de la position d'insertion
    NodeD* courant = head;
    while (courant->next != NULL && courant->next->data < valeur) {
        courant = courant->next;
    }
    
    // Insertion
    nouveau->next = courant->next;
    nouveau->prev = courant;
    
    if (courant->next != NULL) {
        courant->next->prev = nouveau;
    }
    
    courant->next = nouveau;
    
    return head;
}

// 4. Insertion en tête - Liste simplement chaînée circulaire
NodeS* insererTeteCirculaireSimple(NodeS* head, int valeur) {
    NodeS* nouveau = (NodeS*)malloc(sizeof(NodeS));
    nouveau->data = valeur;
    
    if (head == NULL) {
        nouveau->next = nouveau; // Pointe sur lui-même
        return nouveau;
    }
    
    // Parcourir jusqu'au dernier élément
    NodeS* dernier = head;
    while (dernier->next != head) {
        dernier = dernier->next;
    }
    
    nouveau->next = head;
    dernier->next = nouveau;
    
    return nouveau;
}

// 4. Insertion en queue - Liste simplement chaînée circulaire
NodeS* insererQueueCirculaireSimple(NodeS* head, int valeur) {
    NodeS* nouveau = (NodeS*)malloc(sizeof(NodeS));
    nouveau->data = valeur;
    
    if (head == NULL) {
        nouveau->next = nouveau;
        return nouveau;
    }
    
    // Parcourir jusqu'au dernier élément
    NodeS* dernier = head;
    while (dernier->next != head) {
        dernier = dernier->next;
    }
    
    dernier->next = nouveau;
    nouveau->next = head;
    
    return head;
}

// 5. Insertion en tête - Liste doublement chaînée circulaire
NodeD* insererTeteCirculaireDouble(NodeD* head, int valeur) {
    NodeD* nouveau = (NodeD*)malloc(sizeof(NodeD));
    nouveau->data = valeur;
    
    if (head == NULL) {
        nouveau->next = nouveau;
        nouveau->prev = nouveau;
        return nouveau;
    }
    
    NodeD* dernier = head->prev;
    
    nouveau->next = head;
    nouveau->prev = dernier;
    
    head->prev = nouveau;
    dernier->next = nouveau;
    
    return nouveau;
}

// 5. Insertion en queue - Liste doublement chaînée circulaire
NodeD* insererQueueCirculaireDouble(NodeD* head, int valeur) {
    NodeD* nouveau = (NodeD*)malloc(sizeof(NodeD));
    nouveau->data = valeur;
    
    if (head == NULL) {
        nouveau->next = nouveau;
        nouveau->prev = nouveau;
        return nouveau;
    }
    
    NodeD* dernier = head->prev;
    
    nouveau->next = head;
    nouveau->prev = dernier;
    
    dernier->next = nouveau;
    head->prev = nouveau;
    
    return head;
}

// Fonctions utilitaires d'affichage
void afficherListeSimple(NodeS* head) {
    NodeS* courant = head;
    while (courant != NULL) {
        printf("%d -> ", courant->data);
        courant = courant->next;
    }
    printf("NULL\n");
}

void afficherListeDouble(NodeD* head) {
    NodeD* courant = head;
    while (courant != NULL) {
        printf("%d <-> ", courant->data);
        courant = courant->next;
    }
    printf("NULL\n");
}

void afficherListeCirculaireSimple(NodeS* head) {
    if (head == NULL) {
        printf("Liste vide\n");
        return;
    }
    
    NodeS* courant = head;
    do {
        printf("%d -> ", courant->data);
        courant = courant->next;
    } while (courant != head);
    printf("(retour à tête)\n");
}

void afficherListeCirculaireDouble(NodeD* head) {
    if (head == NULL) {
        printf("Liste vide\n");
        return;
    }
    
    NodeD* courant = head;
    do {
        printf("%d <-> ", courant->data);
        courant = courant->next;
    } while (courant != head);
    printf("(retour à tête)\n");
}

// Fonctions de libération mémoire
void libererListeSimple(NodeS* head) {
    NodeS* courant = head;
    NodeS* suivant;
    
    while (courant != NULL) {
        suivant = courant->next;
        free(courant);
        courant = suivant;
    }
}

void libererListeDouble(NodeD* head) {
    NodeD* courant = head;
    NodeD* suivant;
    
    while (courant != NULL) {
        suivant = courant->next;
        free(courant);
        courant = suivant;
    }
}


 main.c

#include "tp2.h"

int main() {
    printf("=== PROGRAMME MODULAIRE TP2 ===\n\n");
    
    // Test 1: Suppression d'occurrences
    printf("1. SUPPRESSION D'OCCURRENCES\n");
    NodeS* liste1 = NULL;
    liste1 = insererListeSimpleTrie(liste1, 5);
    liste1 = insererListeSimpleTrie(liste1, 2);
    liste1 = insererListeSimpleTrie(liste1, 5);
    liste1 = insererListeSimpleTrie(liste1, 3);
    liste1 = insererListeSimpleTrie(liste1, 5);
    
    printf("Liste avant suppression: ");
    afficherListeSimple(liste1);
    
    liste1 = supprimerOccurrences(liste1, 5);
    printf("Liste après suppression des 5: ");
    afficherListeSimple(liste1);
    
    // Test 2: Liste simplement chaînée triée
    printf("\n2. LISTE SIMPLEMENT CHAÎNÉE TRIÉE\n");
    NodeS* liste2 = NULL;
    liste2 = insererListeSimpleTrie(liste2, 10);
    liste2 = insererListeSimpleTrie(liste2, 5);
    liste2 = insererListeSimpleTrie(liste2, 15);
    liste2 = insererListeSimpleTrie(liste2, 7);
    printf("Liste triée: ");
    afficherListeSimple(liste2);
    
    // Test 3: Liste doublement chaînée triée
    printf("\n3. LISTE DOUBLEMENT CHAÎNÉE TRIÉE\n");
    NodeD* liste3 = NULL;
    liste3 = insererListeDoubleTrie(liste3, 20);
    liste3 = insererListeDoubleTrie(liste3, 12);
    liste3 = insererListeDoubleTrie(liste3, 25);
    liste3 = insererListeDoubleTrie(liste3, 18);
    printf("Liste double triée: ");
    afficherListeDouble(liste3);
    
    // Test 4: Liste simplement chaînée circulaire
    printf("\n4. LISTE SIMPLEMENT CHAÎNÉE CIRCULAIRE\n");
    NodeS* liste4 = NULL;
    liste4 = insererTeteCirculaireSimple(liste4, 1);
    liste4 = insererTeteCirculaireSimple(liste4, 2);
    liste4 = insererQueueCirculaireSimple(liste4, 3);
    liste4 = insererQueueCirculaireSimple(liste4, 4);
    printf("Liste circulaire simple: ");
    afficherListeCirculaireSimple(liste4);
    
    // Test 5: Liste doublement chaînée circulaire
    printf("\n5. LISTE DOUBLEMENT CHAÎNÉE CIRCULAIRE\n");
    NodeD* liste5 = NULL;
    liste5 = insererTeteCirculaireDouble(liste5, 10);
    liste5 = insererTeteCirculaireDouble(liste5, 20);
    liste5 = insererQueueCirculaireDouble(liste5, 30);
    liste5 = insererQueueCirculaireDouble(liste5, 40);
    printf("Liste circulaire double: ");
    afficherListeCirculaireDouble(liste5);
    
    // Libération mémoire
    libererListeSimple(liste1);
    libererListeSimple(liste2);
    libererListeDouble(liste3);
    
    // Pour les listes circulaires, besoin de fonctions de libération spécialisées
    // (non implémentées ici pour la concision)
    
    printf("\n=== FIN DU PROGRAMME ===\n");
    return 0;
}


 Compilation et Exécution


# Compilation
gcc -c tp2.c -o tp2.o
gcc -c main.c -o main.o
gcc tp2.o main.o -o tp2_program

# Exécution
./tp2_program


 Fonctionnalités Implémentées

1. Suppression d'occurrences : Supprime toutes les occurrences d'une valeur dans une liste simplement chaînée
2. Insertion triée simple : Insère dans une liste simplement chaînée en maintenant l'ordre croissant
3. Insertion triée double : Insère dans une liste doublement chaînée en maintenant l'ordre croissant
4. Liste circulaire simple : Insertion en tête et en queue avec gestion circulaire
5. Liste circulaire double : Insertion en tête et en queue avec gestion bidirectionnelle circulaire

Ce programme modulaire offre une séparation claire entre l'interface (tp2.h) et l'implémentation (tp2.c), permettant une maintenance et une extensibilité optimales.
