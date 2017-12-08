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
int gettop (node *stack);
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

//get the top element from the stack
int gettop ( node *stack)
{
    if(!isempty(stack))
    {
        int a = stack->next->data;
        return a;
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
gettop(stack)
}

//judge whether the stack is empty
int isempty( node *stack)
{
    if(stack->next == null)
        return 1;
    else
        return 0;
}

int main()
{
    node * stack;
    Init(&stack);
    int i;
    printf("input a integer(at least two integers:");
    while (scanf("%d",&i)==1)
    {
        push(stack,i);
        printf("\ninput a integer:");
    }
    printstack(stack);
    pop(stack);
    pop(stack);
    printf("\n\nAfter pop for two times,the data in stack is:");
    printstack(stack);
    printf("\n\nthe top element is: %d",gettop(stack));

}
