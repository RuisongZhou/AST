#include "head.h"


extern void createCirList(CirList *L, int n)
{
    CirList newptr;
    CirList phead;
    *L = (CirList)malloc(sizeof(CirNode));
    (*L)->next = *L;
    phead = *L;
    int i;

    for ( i = 0 ; i<n ; i++ )
    {
        if ( i == 0)
        {
           // printf("enter the %d people's code.\n",i+1);
           //scanf("%d",&(*L)->data);
           (*L)->data = i+5 ;

            (*L)->number = i+1;

        }
        else
        {
            newptr = (CirList)malloc(sizeof(CirNode));
            //printf("enter the %d people's code.\n",i+1);
            //scanf("%d",&newptr->data);
            newptr->data = i+5;
            newptr->number = i+1;
            while( phead->next != *L)
            phead = phead->next;

            newptr->next = phead->next;
            phead->next = newptr;
        }


    }


}
