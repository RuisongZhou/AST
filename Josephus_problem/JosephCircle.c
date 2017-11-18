#include "head.h"


extern void JosephCircle(CirList *L, int m)
{
    CirList preptr = *L;
    CirList curptr ;
    CirList temp;
    while( preptr->next->number != 1 )
    {
        preptr = preptr->next;
    }
    curptr = preptr->next;
    int i = 0;

      for(  ; curptr != preptr ; )
        {
            i++;
            if ( i ==m )
            {
                printf("%d   ", curptr->number );
                m = curptr->data;
                preptr->next = curptr->next;
                temp = curptr;
                curptr = curptr->next;
                free(temp);
                i = 0;



            }
            else
            {

                preptr = curptr;
                curptr = curptr->next;
            }

        }




    printf("%d   ", curptr->number );




}
