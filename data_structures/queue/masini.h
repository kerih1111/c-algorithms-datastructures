#ifndef MASINI_H_INCLUDED
#define MASINI_H_INCLUDED

typedef struct Node
{
    char marca[30];
    char model[30];
    char nr_inmatriculare[30];
    int timp;
    struct Node* next;
} Node;

typedef struct List
{
    struct Node* head;
} List;

void initList(List *L);
void insertAtHead(List *L);
void deleteBiggestNode(List *L);
void printList(List *L);

#endif // MASINI_H_INCLUDED
