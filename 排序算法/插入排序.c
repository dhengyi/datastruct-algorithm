#include <stdio.h>
int main()
{
	int a[10],i,j,temp;
	for(i=0;i<10;i++)
	scanf("%d",&a[i]);
	for(i=1;i<10;i++)
	{
		if(a[i]<a[i-1])
		{
			temp=a[i];
			for(j=i-1;j>=0&&a[j]>temp;j--)
				a[j+1]=a[j];
			a[j+1]=temp;
		}
	}
	for(i=0;i<10;i++)
	printf("%d ",a[i]);
	return 0;
}
