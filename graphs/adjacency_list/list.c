#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void makeList(List* L, int id)
{
    L->head = (Node *) malloc(sizeof(Node));
    if (L->head == NULL)
        exit(1);
    L->head->next = NULL;
    L->head->prev = NULL;
    L->head->key = id;
    L->head->color = white;
    L->head->d = 0;
    L->head->f = 0;
    L->tail = L->head;

}

Node* createNode(int x)
{
    Node* new = (Node *) malloc(sizeof(Node));
    new->key = x;

    new->color = white;
    new->d = 0;
    new->f = 0;
    new->prev = NULL;
    new->next = NULL;

    return new;
}

void listInsert(List* L, Node* x)
{
    if(x == NULL)
        return;

   x->prev = L->head;
   x->next = L->head->next;

   if(L->head->next != NULL)
   {
       L->head->next->prev = x;
   }
   L->head->next = x;
}

void printList(List* L)
{
    printf("Node %d: ", L->head->key);
    Node* temp;
    temp = L->head->next;
    while(temp != NULL)
    {
        printf("%d -> ", temp->key);
        temp = temp->next;
    }
    printf("NULL\n");
}

void freeList(List *L)
{
    Node* temp;
    while(L->head != NULL)
    {
        temp = L->head->next;
        free(L->head);
        L->head = temp;
    }
}
// stop lists

void INIT_ADJ_LIST(List *G, int n)
{
    for(int i = 0; i < n; i++)
    {
        makeList(&G[i], i);
    }
}

void insertVecini(List *G, int s, int n)
{
    G[s].head->key = s;
    int temp = 0;
    printf("\n--- Adding neighbors for Node %d ---\n", s);
    while(1)
    {
        printf("Node %d is connected to:  (0) to stop", s);
        scanf("%d", &temp);
        if(temp == 0) break;
        if(temp > 0 && temp <= n && temp != s)
        {
            Node* x = createNode(temp);
            listInsert(&G[s], x);
        }
    }
}


void DFS_Visit(List *G, int u)
{
    dfsTime++;
    G[u].head->d = dfsTime;
    G[u].head->color = gray;
    printf("visiting node %d in time %d\n", u, dfsTime);
    Node* ptr = G[u].head->next;
    while(ptr != NULL)
    {
        int v = ptr->key;
        if (G[v].head->color == white)
        {
            G[v].head->prev = G[u].head;
            DFS_Visit(G, v);
        }
        ptr = ptr->next;
    }
    G[u].head->color = black;
    dfsTime++;
    G[u].head->f = dfsTime;
    printf("Finished node %d (Time: %d)\n", u, dfsTime);
}

void enqueue(List *Q, int val)
{
    Node* newNode = createNode(val);


    newNode->prev = Q->tail;
    Q->tail->next = newNode;
    Q->tail = newNode;
}

int dequeue(List *Q)
{
    if(Q->head->next == NULL)
        return -1;

    Node* temp = Q->head->next;
    int value = temp->key;
    Q->head->next = temp->next;
    if(temp->next != NULL)
        temp->next->prev = Q->head;
    else
        Q->tail = Q->head;
    free(temp);
    return value;
}

int isEmpty(List *Q)
{
    return Q->head->next == NULL;
}

void INIT_BFS(List *G, int n)
{
    for(int i = 1; i <= n; i++)
    {
        G[i].head->color = white;
        G[i].head->d = 9999;
        G[i].head->prev = NULL;
    }
}

void BFS(List *G, int s, int n)
{
    INIT_BFS(G, n);
    G[s].head->color = gray;
    G[s].head->d = 0;
    G[s].head->prev = NULL;
    printf("%d ", G[s].head->key);
    List *Q = (List *)malloc(sizeof(List));
    makeList(Q, -1);
    enqueue(Q, s);
    while(!isEmpty(Q))
    {
        int u = dequeue(Q);
        Node* temp = G[u].head->next;
        while(temp != NULL)
        {
            if(G[temp->key].head->color == white)
            {
                G[temp->key].head->color = gray;
                G[temp->key].head->d = G[u].head->d + 1;
                G[temp->key].head->prev = G[u].head;
                enqueue(Q, temp->key);
                printf("%d ", temp->key);
            }
            temp = temp->next;
        }
        G[u].head->color = black;

    }
    free(Q->head);
    free(Q);
}

void PATH(List *G, int s, int v)
{
    if(v==s)
    {
        printf("%d", s);
    }
    else if(G[v].head->prev == NULL)
    {
        printf("no path from %d to %d exists.", s, v);
    }
    else {
        PATH(G, s, G[v].head->prev->key);
        printf(" -> %d", v);
    }
}

