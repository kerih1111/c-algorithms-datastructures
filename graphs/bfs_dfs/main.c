#include <stdio.h>
#include <stdlib.h>
#include "graf.h"

int main()
{
    int n;
    printf("enter number of vertices: ");
    scanf("%d", &n);

    graphInit(n);
    initQueue();

    int src, dest;
    while(1)
    {
        printf("Enter VERTICE and NEIGHBOUR(0 0 to exit)");
        scanf("%d%d", &src, &dest);
        if(src == 0 && dest == 0)
            break;

        if(src > n || dest > n)
        {
            printf("vertice not existing, try again");
        }
        else
        {
            addEdge(src, dest);
        }
    }

    printGraph(n);

    BFS(1);
}
