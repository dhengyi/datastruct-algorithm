#include <stdio.h>
#define NUMBER 10
void shellsort(int a[],int length)
{
	int gap=length/2;
	int i,j,temp; 
	while(gap>=1)//步长要大于1 
	{
		for(i=gap;i<length;i++)//对步长之中的数的遍历 
		{
			temp=a[i];         
			for(j=i-gap;j>=0&&a[j]>temp;j=j-gap)
			{
				a[j+gap]=a[j];
			}
			a[j+gap]=temp;
		}
		gap/=2;
	}
	printf("\n");
}
int main()
{
	int a[NUMBER],i;
	for(i=0;i<NUMBER;i++)
	{
		scanf("%d",&a[i]);
	}
	shellsort(a,NUMBER);
	for(i=0;i<NUMBER;i++)
	{
		printf("%d	",a[i]);
	}
	return 0;
 } 
