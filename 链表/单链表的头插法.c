#include <stdio.h>
#include <stdlib.h>
typedef struct node{
	int a;
	struct node *next;
}str;
int main()
{
	str *pend,*pnew,*phead=NULL,*temp;
	int count=0;
	pend=pnew=(str *)malloc(sizeof(str));
	if(pend==NULL)
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
			pnew->next=phead;
			pend=pnew;
			phead=pnew;
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
	free(temp);
	return 0;
}
