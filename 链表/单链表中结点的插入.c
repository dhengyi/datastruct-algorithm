#include <stdio.h>
#include <stdlib.h>
typedef struct node{
	int a;
	struct node *next;
}str;
int main()
{
	str *pnew,*pend,*phead=NULL,*temp;
	int count=0,index,i;
	pnew=pend=(str *)malloc(sizeof(str));
	if(pnew==NULL)
		exit(1);
	scanf("%d",&pnew->a);
	while(pnew->a!=0)
	{
		count++;
		if(count==1)
		{
			pnew->next=phead;
			pend=pnew;
			phead=pend;
		}
		else
		{
			pnew->next=NULL;
			pend->next=pnew;
			pend=pnew;//只在创建链表的时候需要? 
		}
		pnew=(str *)malloc(sizeof(str));
		if(pnew==NULL)
			exit(1);
		scanf("%d",&pnew->a);
	}
	temp=phead;
	while(temp!=NULL)
	{
		printf("%d ",temp->a);
		temp=temp->next;
	}
	printf("\n");
	pnew=(str *)malloc(sizeof(str));
	if(pnew==NULL)
		exit(1);
	scanf("%d",&pnew->a);
	scanf("%d",&index);
	temp=phead;
	for(i=1;i<index;i++)
		temp=temp->next;
	pnew->next=temp->next;
	temp->next=pnew;
	count++;
	temp=phead;
	while(temp!=NULL)
	{
		printf("%d ",temp->a);
		temp=temp->next;
	}
	free(temp);
	return 0;
}
