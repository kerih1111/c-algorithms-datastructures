#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

typedef struct Node {
    enum{white, gray, black} color;
    int d,f;
    int key;
    struct Node *prev, *next;
} Node;

typedef struct List {
    Node *head;
    Node *tail;
} List;

List G[100];
extern int dfsTime;
// list FUNCTIONS
void makeList(List* L, int id);
void listInsert(List* L, Node* x);
void printList(List* L);
Node* createNode(int x);
void freeList(List *L);

//GRAPH FUNCTIONS
void INIT_ADJ_LIST(List *G, int n);
void insertVecini(List *G, int s, int n);
void DFS_Visit(List *G, int u);

// QUEUE
void enqueue(List *Q, int val);
int dequeue(List *Q);
int isEmpty(List *Q);


// BFS FUNCTIONS
void INIT_BFS(List *G, int n);
void BFS(List *G, int s, int n);

void PATH(List *G, int s, int v);
#endif // LIST_H_INCLUDED
