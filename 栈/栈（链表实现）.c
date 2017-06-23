#include <stdio.h>
#include <stdlib.h>
typedef struct STACK_NODE{
	int value;
	struct STACK_NODE *next;	
}Stacknode;
Stacknode *stack,*temp;
int count=0;
void print()
{
	if(count==0)
		printf("这是一个空栈。\n");
	else
	{
		temp=stack;
		while(temp!=NULL)
		{
			printf("%d ",temp->value);
			temp=temp->next;
		}
		printf("\n");
	}
}
void push(int value)
{
	Stacknode *p;
	p=(Stacknode *)malloc(sizeof(Stacknode));
	if(p==NULL)
		exit(1);
	p->value=value;
	p->next=stack;
	stack=p;
	count++;
}
void pop(Stacknode* frist_node)
{
	stack=frist_node->next;
	free(frist_node); 
}
int top()
{
	return (stack->value);
}
int main()
{
	print();
	push(10); push(9); push(7); push(6); push(5);  
    push(4);  push(3); push(2); push(1); push(0);
    printf("压入元素后的栈:\n");
	print(); 
    pop(stack);
    printf("移除元素后的栈:\n");
    print();
    printf("移除元素后栈顶部的元素为:\n");
    printf("%d",top());
    printf("\n");
    return 0;
}

