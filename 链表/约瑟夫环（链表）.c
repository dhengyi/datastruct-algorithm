/*************************************************************************
	> File Name: 约瑟夫环（链表）.c
	> Author: paranoid
	> Mail: www.champion_hengyi@gmail.com
	> Created Time: 2016年09月17日 星期六 21时49分18秒
	> Description: 
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

typedef struct linklist
{
    int n;
    int passwd;
    struct linklist *next;
}node;

int number;
int count;

node *create_linklist(node * phead);
void print_linklist(node *phead);

node *create_linklist(node *phead)
{
	int i;
    node *p, *q;

    scanf("%d", &number);
	scanf("%d", &count);

    while(number <= 1)
    {
        printf("请输入的人数大于1~~\n");
        scanf("%d", &number);
    }

    p = phead = (node *)malloc(sizeof(node));
    p -> n = 1;
    scanf("%d", &phead -> passwd);

    for(i = 2; i <= number; i++)
    {
        q = (node *)malloc(sizeof(node));

        q -> n = i;
        scanf("%d", &q -> passwd);
        p -> next = q;
        p = q;
    }
    q -> next = phead;

    return phead;
}

void print_linklist(node *phead)
{
	int i;
    node *pre, *temp;
    node *loop;
    node *tmp;

    temp = phead;
    pre = temp;

    while(1)
    {
        if(number == 1)
        {
            printf("n: %d      passwd: %d\n", pre -> n, pre -> passwd);
            break;
        }

        for(i = 0; i < count-1; i++)
        {
            pre = temp;
            temp = temp -> next;
        }

        printf("n: %d      passwd: %d\n", temp -> n, temp -> passwd);
        
        count = temp -> passwd;
        loop = temp;
        temp = temp -> next;
        pre -> next = loop -> next;
        free(loop);

        number--;
    }
}

int main()
{
    node *phead;

    phead = create_linklist(phead);                    

    print_linklist(phead);
	
	return 0;
}
