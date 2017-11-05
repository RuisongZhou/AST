#include<stdio.h>
#include <stdlib.h>
struct num{
    int i;
    struct num * next;
};
int main()
{
    struct num *head = NULL;
    struct num *prev , *current;
    int a;
    while(scanf("%d",&a)==1)
    {
        current = (struct num *)malloc(sizeof (struct num));

        if (head==NULL)
            head = current;
        else
            prev->next = current;

        current->next = NULL;
        current->i=a;
        prev = current;
    }
    if (head == NULL)
        printf("no data.");
    else
    {
        current = head;
        while (current != NULL)
        {
            printf("%d\n",current->i);
            current = current->next;

        }
    }

    return 0;
}
