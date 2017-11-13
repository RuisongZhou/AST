#include<stdio.h>
#include<stdlib.h>
#define null NULL

typedef struct stacknode {
    int data;
    struct stacknode *next;
    }node;

void Init( node **stack);
void push( node *stack , int value);
void pop (node *stack);
void printstack(node *stack);
int isempty(node *stack);

//create a stack
void Init(node **stack)
{
    *stack = (node *)malloc(sizeof(node));
    (*stack)->next = null;
    if ( *stack != null)
        printf(" the stack have already been created.\n\n");
}

// push an element
void push( node *stack , int value)
{
    node *pinsert;
    pinsert = (node *)malloc(sizeof(node));
    pinsert->data = value;
    pinsert->next = stack->next;
    stack->next = pinsert;   //maybe stack is null
}

//pop an element
void pop (node *stack)
{
    if(!isempty(stack))
    {
        node *pnext;
        pnext = stack->next;
        stack->next = pnext->next;
        free(pnext);
        pnext = null;
    }
}


//print the stack
void printstack (node *stack)
{
    if(!isempty(stack))
    {
        node *pmove;
        pmove = stack->next;
        while( pmove != null )
        {
            printf("%d -> ",pmove->data);
            pmove = pmove->next;
        }
        printf("NULL\n");
    }
    else
    printf("the stack is empty");
}

//judge whether the stack is empty
int isempty( node *stack)
{
    if(stack->next == null)
        return 1;
    else
        return 0;
}

//pop the elements like queue
int queueout( node *st1 ,node *st2 )
{   int a ;
    if( !isempty(st2))
    {   node *p;
        p = st2->next;
        a = p->data;
        pop(st2);
    }

    else if( !isempty(st1))
    {
         node *pmove;
        pmove = st1->next;
        while( pmove != null )
        {
            int a=pmove->data;
            push( st2 , a );
            pmove = pmove->next;
        }
         node *p;
        p = st2->next;
        a = p->data;
        pop(st2);
    }

    return a;

}
int main()
{
    node *stackin;
    node *stackout;
    Init(&stackin);
    Init(&stackout);
    printf("Use two stacks to implement the queue.\n\n");
    printf("input a integer:");
    int i,k=0;
    int temp;
    while (scanf("%d",&i)==1)
    {
        push(stackin,i);
        printf("\ninput a integer:");
        k++;
    }
    printf("\n\nthe output is:\n\n");
    for ( i = 0 ; i < k ; i ++ )
    {
        temp = queueout( stackin , stackout );
        printf("%d  ",temp);
    }
    return 0;



}
