#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int n;
int st[20];
int solutions = 0;

void afisare()
{
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(st[i] == j)
            {
                printf("R ");
            }
            else{
                printf("# ");
            }

        }
        printf("\n");
    }
    printf("\n");
}

int valid(int k)
{
    for(int i = 1; i < k; i++)
    {
        if(st[i] == st[k])
            return 0;
        if(abs(k-i) == abs(st[k] - st[i]))
            return 0;
    }
    return 1;
}

void backtrack(int k)
{
    if(k == n+1)
    {
        afisare();
        solutions++;
    }

    for(int i = 1; i <= n; i++)
    {
        st[k] = i;

        if(valid(k))
            backtrack(k+1);
    }
}

int main()
{
    printf("enter n: ");
    scanf("%d", &n);

    backtrack(1);

    printf(" TOTAL SOLUTII : %d !", solutions);
}
