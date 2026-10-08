#include <stdio.h>
#include <stdlib.h>
#include "graf.h"

int main()
{
    int n;
    printf("Cati vertices vrei sa introduci?");
    scanf("%d", &n);

    graphInit(n);


    int sursa, destinatie, cost;
    printf("Introdu muchiile (Sursa Destinatie Cost. 0 0 0 pt stop\n ");
    while(1)
    {

        scanf("%d %d %d", &sursa, &destinatie, &cost);
        if(sursa == 0)
        {
            break;
        }
        if(sursa > n || destinatie > n)
        {
            printf("Nu se poate! ");
        }
        else
            addEdge(sursa, destinatie, cost);
    }

    printGraph(n);


    dijkstra(n, 1);

    prim(n, 1);
}
