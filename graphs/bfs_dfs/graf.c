#include <stdio.h>
#include <stdlib.h>
#include "graf.h"

void graphInit(int n)
{
    for(int i = 1; i <= n; i++)
    {
        G[i].head = (Node *)malloc(sizeof(Node));
        G[i].head->dest = i;
        G[i].head->next = NULL;
        G[i].head->color = white;
    }
}


void addEdge(int src, int dest)
{
    Node* newNode = (Node *)malloc(sizeof(Node));

    newNode->next = G[src].head->next;
    newNode->color = white;
    newNode->dest = dest;
    G[src].head->next = newNode;


    newNode = (Node *)malloc(sizeof(Node));
    newNode->next = G[dest].head->next;
    newNode->color = white;
    newNode->dest = src;
    G[dest].head->next = newNode;

}

void printGraph(int n)
{
    for(int i = 1; i <= n; i++)
    {
        Node* temp = G[i].head->next;
        printf("Vertice #%d ", i);
        while(temp != NULL)
        {
            printf("-> %d", temp->dest);
            temp = temp->next;
        }
        printf("\n");
    }
}

void DFS(int src)
{
    G[src].head->color = gray;
    printf("%d, ", G[src].head->dest);
    Node* temp = G[src].head->next;
    while(temp != NULL)
    {
        if(G[temp->dest].head->color == white)
            DFS(temp->dest);
        temp = temp -> next;
    }
    G[src].head->color = black;
}


void initQueue()
{
    Q.head = (Node*)malloc(sizeof(Node));
    Q.head->next = NULL;

    tail = Q.head;
}
int isEmpty()
{
    return Q.head->next == NULL;
}
void enqueue(int x)
{
    Node* newNode = (Node *)malloc(sizeof(Node));
    newNode->dest = x;
    newNode->next = NULL;

    tail->next = newNode;
    tail = newNode;
}
int dequeue()
{
    if(isEmpty()) return -1;
    Node* deleted = Q.head->next;


    Q.head->next = deleted->next;

    int result = deleted->dest;

    if(Q.head->next == NULL)
            tail = Q.head;

    free(deleted);
    return result;
}


void BFS(int src)
{
    G[src].head->color = gray;
    enqueue(src);

    while(!isEmpty())
    {
    int u = dequeue();
    printf("%d, ", u);
    Node* temp = G[u].head->next;
    int enqueuer;
    while(temp != NULL)
    {
        if(G[temp->dest].head->color == white)
        {
            enqueuer = temp->dest;
            enqueue(enqueuer);
            G[temp->dest].head->color = gray;
        }
        temp = temp->next;
    }
    G[u].head->color = black;
    }

}
