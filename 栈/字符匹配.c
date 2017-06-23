#include <stdio.h>
#include <string.h>
#define NUMBER 100
char stack[NUMBER];
int stack_element=-1,j=0;
void enstack(char value)
{
	stack[++stack_element]=value;
}
void destack()
{
	stack_element--; 
} 
void pipei(char value)
{
	if((stack[stack_element]=='('&&value==')')||(stack[stack_element]=='{'&&value=='}')||(stack[stack_element]=='['&&value==']'))
	{
		destack();
	}
}
int main()
{
	char ch[NUMBER];
	int i;
	
	gets(ch);
	for(i=0;i<strlen(ch);i++)
	{
		if(ch[i]=='('||ch[i]=='{'||ch[i]=='[')
		{
			enstack(ch[i]);
		}
		if(ch[i]==')'||ch[i]=='}'||ch[i]==']')
		{
			pipei(ch[i]);
		}
	}
	if(stack_element==-1)
		printf("yes.\n");
	else
		printf("no.\n");
	return 0;
}
