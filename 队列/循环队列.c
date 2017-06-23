#include <stdio.h>
#include <stdlib.h>
struct queue{
	int length;
	int head;
	int tail;
	int *p;
};
struct queue *str;
int count=0;
void initqueue()
{
	str->length=8;
	str->head=0;
	str->tail=0;
	str->p=(int *)malloc(sizeof(int)*str->length);
	if(str->p==NULL)
		exit(1);
}
void enqueue(int value)
{
	str->tail=(str->tail+1)%str->length;
	if(str->tail==str->head)
		printf("这个对列是满的。\n");
	else
		str->p[str->tail]=value;
	count++;
}
void dequeue()
{
	int i;
	for(i=2;i<=count;i++)
	{
		str->p[i-1]=str->p[i];
	}
	count--;
} 
int main()
{	
	str=(struct queue *)malloc(sizeof(struct queue));
	if(str==NULL)
		exit(1);
	int i;
	initqueue();
	enqueue(10);enqueue(9);enqueue(8);enqueue(7);enqueue(6);
	enqueue(5);
	dequeue();
	for(i=1;i<=count;i++)
	{
		printf("%d ",str->p[i]);
	}
	return 0;
}
