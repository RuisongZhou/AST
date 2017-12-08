#include<stdio.h>
#include <stdlib.h>
struct num{
    int i;
    struct num * next;
};
int main()
{   //establish a new list
    struct num *head = NULL;
    struct num *prev , *current;
    int a;
    printf("Please enter the value(q to quit):\n");
    while(scanf("%d",&a)==1)        //assign the value to the list
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


    //Normal print
    printf("Normal print is:\n");
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


    //Reverse print
    printf("Reverse print is:\n");
    prev = NULL;
    while (head != NULL)
    {
        current = head->next;
        head->next = prev;
        prev = head;
        head = current;
    }
    current = prev;
    while (current != NULL)
        {
            printf("%d\n",current->i);
            current = current->next;

        }
    return 0;
}
