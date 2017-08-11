#include <stdio.h>
#include <stdlib.h>

#define NUMBER 10

typedef struct node{
	int a;
	struct node *left;
	struct node *right;
}Node;

Node *creat_tree(int a[],int length)
{
	Node *tmp,*before,*pt;
	int i,flag=0;
	
	pt=(Node *)malloc(sizeof(Node));
	if(pt==NULL)
		exit(1);
		
	tmp=(Node *)malloc(sizeof(Node));
	if(tmp==NULL)
		exit(1);
		
	pt->a=a[0];
	pt->left=NULL;
	pt->right=NULL;
	
	for(i=1;i<length;i++)
	{
		tmp=pt;
		while(tmp!=NULL)
		{
			if(tmp->a>a[i])
			{
				flag=-1;
				before=tmp;
				
				if(tmp->left!=NULL)
					tmp=tmp->left;
				else
					break;				
			}
			if(tmp->a<a[i])
			{
				flag=1;
				before=tmp;
				
				if(tmp->right!=NULL)
					tmp=tmp->right;
				else
					break;
			}
		}
		
		if(flag==-1)
		{
			before->left=(Node *)malloc(sizeof(Node));
			before->left->a=a[i];
			before->left->left=NULL;
			before->left->right=NULL;
		}
		
		if(flag==1)
		{
			before->right=(Node *)malloc(sizeof(Node));
			before->right->a=a[i];
			before->right->left=NULL;
			before->right->right=NULL;
		}
	}
	
	return pt;
}

void print(Node *str)
{
	if(str==NULL) return;
	
    print(str->left);
    print(str->right);
    printf("%d\n", str->a);//∫Û–Ú±È¿˙ 
}

int main()
{
	Node *str;
	
	str=(Node *)malloc(sizeof(Node));
	if(str==NULL)
		exit(1);
		
	int a[NUMBER],i;
	
	for(i=0;i<NUMBER;i++)
	{
		scanf("%d",&a[i]);
	}
	
	str=creat_tree(a,NUMBER);
	
	print(str);
	
	return  0;
}
