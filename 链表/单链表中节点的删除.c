#include <stdio.h>
#include <stdlib.h>
typedef struct node{
	int a;
	struct node *next;
}str;
str *del(str* phead,int index)
{
	str *p,*pre;
	p=phead;
	int i;
	for(i=1;i<index;i++)
	{
		pre=p;
		p=p->next;
	}
	pre->next=p->next;
	if(i==1)
	{
		phead=p->next;
	}
	return phead;
	free(p);
}
int main()
{
	str *pnew,*pend,*phead=NULL,*temp;
	int count=0,index;
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
			pend=pnew;
		}
		pnew=(str *)malloc(sizeof(str));
		if(pnew==NULL)
			exit(1);
		scanf("%d",&pnew->a);
	}
	scanf("%d",&index);
	phead=del(phead,index);
	count--;
	temp=phead;
	while(temp!=NULL)
	{
		printf("%d ",temp->a);
		temp=temp->next;
	}
	free(phead);
	return 0;
}
