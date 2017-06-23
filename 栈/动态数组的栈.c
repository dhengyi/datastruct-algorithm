#include <stdio.h>
#include <stdlib.h>
int *stack,top_element=-1,i; 
void create_stack()
{
	int size;
	scanf("%d",&size);
	if(size!=0)
	{
		stack=(int *)malloc(sizeof(int)*size);
		if(stack==NULL)
			exit(1);
	}
	if(size==0)
	{
		exit(0);
	}
}
void print()
{
	i=top_element;
	if(i==-1)
		printf("这是个空栈.\n");
	if(i!=-1)
	{
		while(i>=0)
		{
			printf("%d	",stack[i--]);
		}
	printf("\n");
	}
}
void push(int value)
{
	top_element+=1;
	stack[top_element]=value;
}
void pop()
{
	top_element-=1;
}
int top()
{
	return (stack[top_element]);
}
int main()
{
	create_stack();
	print();
	push(9);push(8);push(7);push(6);push(5);
	push(4);push(3);push(2);push(1);push(0);
	print();
	pop();
	printf("此时栈的顶部元素是：%d\n",top());
	printf("此时栈内的元素是：\n");
	print();
	free(stack);
	return 0;
 } 
