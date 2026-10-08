#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int dfsTime = 0;

int main()
{
    int N;
    printf("enter how many vertices");
    scanf("%d", &N);
    List myLists[N + 1];

    for(int i = 1; i <= N; i++) {
        makeList(&myLists[i], i);
    }


    for(int i = 1; i <= N; i++) {
        insertVecini(myLists, i, N);
    }

    printf("\n=== Starting BFS Execution (Source: Node 1) ===\n");
    BFS(myLists, 1, N);

    printf("Node | BFS Distance (d) | Parent\n");
    printf("-----|------------------|-------\n");
    for(int i = 1; i <= N; i++) {
        int p = (myLists[i].head->prev != NULL) ? myLists[i].head->prev->key : -1;
        printf("  %d  |        %2d        |   %2d  \n",
               i, myLists[i].head->d, p);
    }

    int target = 5;
    printf("\nShortest path to %d: ", target);
    PATH(myLists, 1, target);

    for(int i = 1; i <= N; i++) {
        myLists[i].head->color = white;
        myLists[i].head->prev = NULL;
    }
    dfsTime = 0;

    printf("\n=== Starting DFS Execution ===\n");
    for(int i = 1; i <= N; i++) {
        if(myLists[i].head->color == white) {
            printf("Starting new search at Node %d...\n", i);
            DFS_Visit(myLists, i);
        }
    }

    printf("\n=== Final DFS Timestamps ===\n");
    printf("Node | Discovery (d) | Finish (f)\n");
    printf("-----|---------------|-----------\n");
    for(int i = 1; i <= N; i++) {
        printf("  %d  |       %2d      |     %2d    \n",
               i, myLists[i].head->d, myLists[i].head->f);
    }

    target = 5;
    printf("\nShortest path to %d: ", target);
    PATH(myLists, 1, target);

    return 0;
}
