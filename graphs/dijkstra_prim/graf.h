#ifndef GRAF_H_INCLUDED
#define GRAF_H_INCLUDED

typedef struct Node{

    int dest;
    int weight;
    struct Node* next;

}Node;

typedef struct List{

    struct Node* head;

} List;

List G[100];

void graphInit(int n);
void addEdge(int src, int dest, int weight);
void printGraph(int n);
void dijkstra(int n, int start);
void prim(int n, int start);


#endif // GRAF_H_INCLUDED
