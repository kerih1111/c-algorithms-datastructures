#include <stdio.h>
#include <stdlib.h>
#include "masini.h"

int main()
{
    List myList;
    initList(&myList);

    int s;
    printf("cate masini introduci? ");
    scanf("%d", &s);
    for(int i = 1; i <= s; i++)
    {
        printf("Masina #%d: ", i);
        insertAtHead(&myList);
    }

    printList(&myList);


}
