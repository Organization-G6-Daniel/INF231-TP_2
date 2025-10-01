#include <stdio.h>
#include <stdlib.h>
#include "tp2.h"

// ==== LISTE SIMPLEMENT CHAÎNÉE ====

// Création d’une liste d’exemple
Node* createSampleList() {
    Node* head = NULL;
    Node* tail = NULL;
    int values[] = {10, 20, 30, 20, 40, 20, 50};
    int n = sizeof(values) / sizeof(values[0]);

    for (int i = 0; i < n; i++) {
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->data = values[i];
        newNode->next = NULL;
        if (head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    return head;
}

// Insertion triée dans une liste simplement chaînée
Node* insertSorted(Node* head, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL || head->data >= value) {
        newNode->next = head;
        return newNode;
    }

    Node* current = head;
    while (current->next != NULL && current->next->data < value) {
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;
    return head;
}

// Supprimer toutes les occurrences d’une valeur
Node* deleteAllOccurrences(Node* head, int key) {
    while (head != NULL && head->data == key) {
        Node* temp = head;
        head = head->next;
        free(temp);
    }
    Node* current = head;
    while (current != NULL && current->next != NULL) {
        if (current->next->data == key) {
            Node* temp = current->next;
            current->next = temp->next;
            free(temp);
        } else {
            current = current->next;
        }
    }
    return head;
}

// Affichage liste simplement chaînée
void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Libération mémoire
void freeList(Node* head) {
    while (head != NULL) {
        Node* temp = head;
        head = head->next;
        free(temp);
    }
}

// ==== LISTE DOUBLEMENT CHAÎNÉE ====

// Création liste doublement chaînée triée d’exemple
DNode* createSampleDoublyList() {
    DNode* head = NULL;
    int values[] = {10, 20, 30, 40, 50};
    int n = sizeof(values) / sizeof(values[0]);

    for (int i = 0; i < n; i++) {
        DNode* newNode = (DNode*)malloc(sizeof(DNode));
        newNode->data = values[i];
        newNode->next = NULL;
        newNode->prev = NULL;

        if (head == NULL) {
            head = newNode;
        } else {
            DNode* tail = head;
            while (tail->next != NULL) tail = tail->next;
            tail->next = newNode;
            newNode->prev = tail;
        }
    }
    return head;
}

// Insertion triée dans une liste doublement chaînée
DNode* insertSortedDoubly(DNode* head, int value) {
    DNode* newNode = (DNode*)malloc(sizeof(DNode));
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (head == NULL || head->data >= value) {
        newNode->next = head;
        if (head != NULL) head->prev = newNode;
        return newNode;
    }

    DNode* current = head;
    while (current->next != NULL && current->next->data < value) {
        current = current->next;
    }

    newNode->next = current->next;
    newNode->prev = current;
    if (current->next != NULL) {
        current->next->prev = newNode;
    }
    current->next = newNode;
    return head;
}

// Affichage liste doublement chaînée
void printDoublyList(DNode* head) {
    DNode* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Libération mémoire liste doublement chaînée
void freeDoublyList(DNode* head) {
    while (head != NULL) {
        DNode* temp = head;
        head = head->next;
        free(temp);
    }
}
