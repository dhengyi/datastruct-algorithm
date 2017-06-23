#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int a;
    struct node *next;
}str;
struct queue{
    str *front;
    str *rear;
    int count;
};
str *pnew;
struct queue *eve;
void init_queue()
{
    eve->count=0;
    eve->front=(str *)malloc(sizeof(str));
    if(eve->front==NULL)
        exit(1);
    eve->rear=(str *)malloc(sizeof(str));
    if(eve->rear==NULL)
        exit(1);
    eve->front=NULL;
    eve->rear=NULL;
}
void enqueue(int value)
{
    pnew=(str *)malloc(sizeof(str));
    if(pnew==NULL)
        exit(1);
    pnew->next=NULL;
    pnew->a=value;
    eve->count++;
    if(eve->count==1)
    {
        eve->front=pnew;
        eve->rear=pnew;
    }
    else
    {
        eve->rear->next=pnew;
        eve->rear=pnew;
    }
    printf("%d ",eve->rear->a);
}
void dequeue()
{
    str *pre;
    pre=(str*)malloc(sizeof(str));
    if(pre==NULL)
        exit(1);
    pre=eve->front;
    eve->front=eve->front->next;
    free(pre);
    eve->count--;
    if(eve->count==0)
        eve->rear=NULL;
}
void top_queue()
{
    printf("top:%d\n",(eve->front->a));
}
void print()
{
    str *temp;
    temp=(str *)malloc(sizeof(str));
    if(temp==NULL)
        exit(1);
    temp=eve->front;
    while(temp!=NULL)
    {
        printf("%d ",temp->a);
        temp=temp->next;
    }
    printf("\n");
}
int main()
{
    eve=(struct queue *)malloc(sizeof(struct queue));
    if(eve==NULL)
        exit(1);
    init_queue();
    enqueue(9);enqueue(8);enqueue(7);enqueue(6);enqueue(5);
    enqueue(4);enqueue(3);enqueue(2);enqueue(1);enqueue(0);
    printf("\n");
    print();
    dequeue();
    dequeue();
    print();
    dequeue();
    print();
    top_queue();
    return 0;
}
