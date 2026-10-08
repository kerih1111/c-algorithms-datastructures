#include <stdio.h>
#include <stdlib.h>
#include "graf.h"

void graphInit(int n)
{
    for(int i = 1; i <= n; i++)
    {
        G[i].head = (Node *)malloc(sizeof(Node));
        G[i].head->dest = 0;
        G[i].head->weight = 0;
        G[i].head->next = NULL;
    }
}
void addEdge(int src, int dest, int weight)
{
    Node* newNode = (Node *)malloc(sizeof(Node));

    newNode->weight = weight;
    newNode->dest = dest;

    newNode->next = G[src].head->next;
    G[src].head->next = newNode;

    newNode = (Node *)malloc(sizeof(Node));
    newNode->weight = weight;
    newNode->dest = src;
    newNode->next = G[dest].head->next;
    G[dest].head->next = newNode;



}

void printGraph(int n)
{
    Node *temp;
    for(int i = 1; i <= n; i++)
    {
        temp = G[i].head->next;
        printf("Head: %d ", i);
        while(temp != NULL)
        {
            printf("-> (%d | %d)", temp->dest, temp->weight);

            temp = temp ->next;
        }
        printf("-> NULL\n");
    }
}


void dijkstra(int n, int start)
{
    int dp[100];
    int visited[100];

    for(int i = 0; i <= n; i++)
    {
        dp[i] = 9999;
        visited[i] = 0;
    }

    dp[start] = 0;


    for(int count = 1; count < n; count++)
    {
        int min = 9999;
        int idx = -1;
        for(int i = 1; i <= n; i++)
        {
            if (dp[i] <= min && visited[i] == 0)
            {
                min = dp[i];
                idx = i;
            }
        }
            if(idx == -1) break;
            visited[idx] = 1;

            Node* temp = G[idx].head->next;


            while(temp != NULL)
            {
            int vecin = temp->dest;
            int cost = temp->weight;
                if(dp[idx] + cost < dp[vecin] && visited[vecin] == 0)
                {
                    dp[vecin] = dp[idx] + cost;
                }
                temp = temp->next;
        }
    }

    printf("\ndrumurile minime de la nodul %d ", start);
    for(int i = 1; i <= n; i++)
    {
        printf("Nod %d : %d\n",i , dp[i]);
    }


}


void prim(int n, int start)
{
    int dp[100];
    int visited[100];
    int total_mst_cost = 0;

    for(int i = 0; i <= n; i++)
    {
        dp[i] = 9999;
        visited[i] = 0;
    }

    dp[start] = 0;


    for(int count = 1; count < n; count++)
    {
        int min = 9999;
        int idx = -1;
        for(int i = 1; i <= n; i++)
        {
            if (dp[i] <= min && visited[i] == 0)
            {
                min = dp[i];
                idx = i;
            }
        }
            if(idx == -1) break;
            visited[idx] = 1;

            Node* temp = G[idx].head->next;


            while(temp != NULL)
            {
            int vecin = temp->dest;
            int cost = temp->weight;
                if(cost < dp[vecin] && visited[vecin] == 0)
                {
                    dp[vecin] = cost;
                }
                temp = temp->next;
        }
    }

    printf("\n Costul total al arborelui minim ");
    for(int i = 1; i <= n; i++)
    {
        if(dp[i] != 9999)
            total_mst_cost += dp[i];
    }
    printf("%d\n", total_mst_cost);


}

