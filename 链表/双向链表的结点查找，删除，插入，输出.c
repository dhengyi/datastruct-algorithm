#include <stdio.h>
#include <stdlib.h>
typedef struct node{
	int a;
	struct node *next;
	struct node *ago;
}str;
int main()
{
	str *pend,*pnew,*phead,*temp;
	int count=0,index=0,i,n;
	pend=pnew=(str *)malloc(sizeof(str));
	if(pend==NULL)
		exit(1);
	scanf("%d",&pend->a);
	while(pnew->a!=0)
	{
		count++;
		if(count==1)
		{
			pnew->next=phead;
			pnew->ago=phead;
			pend=pnew;
			phead=pend;
			phead->ago=NULL;
		}
		else
		{
			pnew->next=NULL;
			pnew->ago=pend;
			pend->next=pnew;
			pend=pnew;
		}
		pnew=(str *)malloc(sizeof(str));
		if(pnew==NULL)
			exit(1);
		scanf("%d",&pnew->a);
	}
	scanf("%d",&n);
	temp=phead;
	while(temp!=NULL)
	{
		index++;
		if(temp->a==n)
		{
			printf("%d\n",index);
			break;
		}
		temp=temp->next;
	}
	scanf("%d",&n);
	temp=phead;
	for(i=1;i<n;i++)
		temp=temp->next;
	temp->next->ago=temp->ago;
	temp->ago->next=temp->next;
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
	temp=phead;
	scanf("%d",&n);
	for(i=1;i<n;i++)
		temp=temp->next;
	pnew->next=temp->next;
	temp->next->ago=pnew;
	temp->next=pnew;
	pnew->ago=temp;
	temp=pend;
	while(temp!=NULL)
	{
		printf("%d ",temp->a);
		temp=temp->ago;
	}
	free(temp);
	return 0;
 } 
