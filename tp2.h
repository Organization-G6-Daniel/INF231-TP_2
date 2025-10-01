#ifndef FONCTION_H
#define FONCTION_H

// ==== Liste simplement chaînée ====
typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createSampleList();
Node* insertSorted(Node* head, int value);
Node* deleteAllOccurrences(Node* head, int key);
void printList(Node* head);
void freeList(Node* head);

// ==== Liste doublement chaînée ====
typedef struct DNode {
    int data;
    struct DNode* prev;
    struct DNode* next;
} DNode;

DNode* createSampleDoublyList();
DNode* insertSortedDoubly(DNode* head, int value);
void printDoublyList(DNode* head);
void freeDoublyList(DNode* head);

#endif
