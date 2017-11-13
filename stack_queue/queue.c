#include<stdio.h>
#include<stdlib.h>

typedef struct qnode{
    int data;
    struct queuenode *next;
}qnode,*queueptr;

typedef struct {
    queueptr front,rear;
}linkqueue;


void Init(linkqueue *);//创建队列queue
void enqueue(linkqueue *,int a);//让a进入队列queue的队尾
int dequeue(linkqueue *);//让队头元素出队
int getfront(linkqueue *);//获取队头元素但不弹出

void Init(linkqueue *q)
{
    q->front = q->rear = (queueptr)malloc(sizeof(qnode));
    if( q->front == NULL )
        printf(" the memory is lacking.");
    q->front->next = NULL;

}
void enqueue(linkqueue *q,int a)
{
    queueptr p = (queueptr)malloc(sizeof(qnode));
    if( p == NULL)
        printf("memory is  allocated faily.");
    p->data = a;
    p->next = NULL;
    q->rear->next = p;
    q->rear = p;
}
int dequeue(linkqueue *q)
{
    queueptr p;
    if( q->front == q->rear )
        printf("no element");
    p = q->front->next;
    int temp = p->data;
    q->front->next = p ->next;
    if( q->rear ==p)
        q->rear = q->front;
    free(p);
    return temp;
}

int getfront(linkqueue *q)
{
    if( q->front == q->rear)
        printf("no element");
    else
        {
            queueptr temp = q->front->next;
            return temp->data;
        }
}


int main()
{
    linkqueue queue;
    Init(&queue);
    int i;
    printf("input a integer(at least two integers):");
    while (scanf("%d",&i)==1)
    {
        enqueue(&queue,i);
        printf("\ninput a integer:");
    }
    printf("\n\nthe first element is %d\n",getfront(&queue));

    int a;
    while(queue.front != queue.rear)
    {
    a=dequeue(&queue);
    printf("%d <- ",a);
    }
    printf("NULL");
    return 0;
}
