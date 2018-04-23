#include "head.h"


extern void createCirList(CirList *L, int n)
{
    CirList newptr;
    CirList phead;
    *L = (CirList)malloc(sizeof(CirNode));
    (*L)->next = *L;
    phead = *L;    //构建循环链表
    int i;

    for ( i = 0 ; i<n ; i++ )
    {
        if ( i == 0) //第一个节点
        {
           printf("enter the %d people's code.\n",i+1);
           scanf("%d",&(*L)->data);
           (*L)->number = i+1;

        }
        else。  //第n个节点
        {
            newptr = (CirList)malloc(sizeof(CirNode));   //创建节点
            printf("enter the %d people's code.\n",i+1);
            scanf("%d",&newptr->data);
            newptr->number = i+1;
            while( phead->next != *L)   //找到头节点的前一个节点
            phead = phead->next;

            newptr->next = phead->next;   //插入节点
            phead->next = newptr;
        }


    }


}
