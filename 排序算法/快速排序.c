#include <stdio.h>
#include <stdlib.h>
#define NUMBER 10
void swap(int *x,int *y)
{
	int temp;
	temp=*x;
	*x=*y;
	*y=temp;
}
int choose(int m,int n)
{
	int k;
	k=(m+n)/2;
	return k;
}
void quicksort(int a[],int l,int r)
{
	int i,j,key;
	i=l,j=r;
	key=a[l];
	if(l<r)
	{
		while(i<j)
		{
			while(i<j&&a[j]>key)
			{
				j--;
			}
			if(i<j)
			{
				a[i]=a[j];
				i++;
			}
			while(i<j&&a[i]<key)
			{
				i++;
			}
			if(i<j)
			{
				a[j]=a[i];
				j--; 
			}
		}
		a[i]=key;
		quicksort(a,l,i-1);
		quicksort(a,i+1,r);
	}
}
int main()
{
	int a[NUMBER],i,q;
	for(i=0;i<NUMBER;i++)
	{
		a[i]=rand()%10;
	}
	q=choose(0,NUMBER-1);
	swap(&a[0],&a[q]);
	quicksort(a,0,NUMBER-1);
	for(i=0;i<NUMBER;i++)
	{
		printf("%d	",a[i]);
	}
	return 0;
 } 
