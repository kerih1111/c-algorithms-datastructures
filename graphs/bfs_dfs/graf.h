#ifndef GRAF_H_INCLUDED
#define GRAF_H_INCLUDED

typedef struct Node
{
    enum {white, gray, black} color;
    int dest;
    struct Node* next;

} Node;

typedef struct
{
   struct Node* head;
} List;


List G[100];
List Q;
Node *tail;

void graphInit(int n);
void addEdge(int src, int dest);
void printGraph(int n);
void DFS(int src);
void BFS(int src);


// queue

void initQueue();
int isEmpty();
void enqueue(int x);
int dequeue();
#endif // GRAF_H_INCLUDED
