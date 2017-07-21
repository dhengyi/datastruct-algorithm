#include <stdio.h>
#include <stdlib.h>
struct STUDENT{
	int number;
	int grade;
	struct STUDENT *next;
};
struct STUDENT *sort(struct STUDENT *pHead)
{
	struct STUDENT *first,*t,*p,*q;
	first=pHead->next;
	pHead->next=NULL;
    while(first!=NULL)
    {
        for(t=first,q=pHead;((q!=NULL)&&(q->number<t->number));p=q,q=q->next); 
        	first=first->next;
        if(q==pHead)
        {  
            pHead=t;  
        }  
        else
        {  
        	p->next=t;
        }  
        t->next=q;
    }
    return pHead; 
}
int main()
{
	struct STUDENT *pHead1=NULL,*pHead2=NULL,*pNew1,*pEnd1,*pNew2,*pEnd2,*pHead;
	struct STUDENT *Temp;
	int m,n,count=1;
	scanf("%d %d",&m,&n);
	while(count<=m)
	{
		pNew1=(struct STUDENT*)malloc(sizeof(struct STUDENT));
		if(pNew1==NULL)
			exit(0);
		scanf("%d",&pNew1->number);
		scanf("%d",&pNew1->grade);
		if(count==1)
		{
			pNew1->next=pHead1;
			pEnd1=pNew1;
			pHead1=pNew1;
		}
		else
		{
			pNew1->next=NULL;
			pEnd1->next=pNew1;
			pEnd1=pNew1;
		}
		count++;
	}
	count=1;
	while(count<=n)
	{
		pNew2=(struct STUDENT*)malloc(sizeof(struct STUDENT));
		if(pNew2==NULL)
			exit(0);
		scanf("%d",&pNew2->number);
		scanf("%d",&pNew2->grade);
		if(count==1)
		{
			pNew2->next=pHead2;
			pEnd2=pNew2;
			pHead2=pNew2;
		}
		else
		{
			pNew2->next=NULL;
			pEnd2->next=pNew2;
			pEnd2=pNew2;
		}
		count++;
	}
	pEnd1->next=pHead2;
	pEnd1=pHead2;
	pHead=sort(pHead1);
	Temp=(struct STUDENT*)malloc(sizeof(struct STUDENT));
	if(Temp==NULL)
		exit(0);
	Temp=pHead;
	while(Temp!=NULL)
	{
		printf("%d ",Temp->number);
		printf("%d",Temp->grade);
		printf("\n");
		Temp=Temp->next;
	}
	free(pHead);
	return 0;
 } 
