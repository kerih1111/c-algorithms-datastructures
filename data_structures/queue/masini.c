#include <stdio.h>
#include <stdlib.h>
#include "masini.h"

void initList(List *L)
{
    L->head = (Node *)malloc(sizeof(Node));
    L->head->timp = -1;
    L->head->next = NULL;
    L->head->marca[0] = '\0';
    L->head->model[0] = '\0';
    L->head->nr_inmatriculare[0] = '\0';
}
void insertAtHead(List *L)
{
    Node* newNode = (Node *)malloc(sizeof(Node));
    printf("Marca: ");
    scanf(" %[^\n]", newNode->marca);
    printf("Model: ");
    scanf(" %[^\n]", newNode->model);
    printf("Nr Inmatriculare: ");
    scanf(" %[^\n]", newNode->nr_inmatriculare);
    printf("Timp pentru finisare(in minute): ");
    scanf("%d", &newNode->timp);

    Node* p = L->head;
    while(p->next != NULL && p->next->timp < newNode->timp)
    {
        p = p ->next;
    }
    newNode -> next = p->next;
    p->next = newNode;

}

void printList(List *L)
{
    Node* temp;
    temp = L->head->next;
    int i = 1;
    while(temp != NULL)
    {
        printf("Masina %d, Marca: %s, Model %s, Nr Inmatriculare %s, TIMP: %d", i, temp->marca, temp->model, temp->nr_inmatriculare, temp->timp);
        temp = temp -> next;
        i++;
        printf("\n");
    }
    printf("\n");
}

