#include <stdio.h>
#define NUMBER 100
int stack[NUMBER],top_element=-1,i;
void push(int value)
{
	top_element+=1;
	stack[top_element]=value;
}
void pop()
{
	top_element--;
}
int top()
{
	return (stack[top_element]);
}
void print()
{
	i=top_element;
	if(i==-1)
		printf("这是个空堆栈.\n");
	if(i!=-1)
	{
		while(i>=0)
			printf("%d	",stack[i--]);
	}
	printf("\n");
}
int main()
{
	print();
	push(10);push(9);push(7);push(6);push(5);  
    push(4);push(3);push(2);push(1);push(0);
    printf("压入后的堆栈：\n");
    print();
    pop();
    pop();
    printf("弹出两个元素后的堆栈:\n");
    print();
    printf("\n");
    printf("top的值:%d\n",top());
    return 0;
}
