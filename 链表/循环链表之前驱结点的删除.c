/*************************************************************************
	> File Name: 循环链表之前驱结点的删除.c
	> Author: paranoid
	> Mail: www.champion_hengyi@gmail.com
	> Created Time: 2016年09月11日 星期日 16时06分33秒
	> Description: 
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

typedef struct linklist
{
    int n;
    struct linklist *next;
}node;

int number = 0;
node *temp;

node *create_linklist(node *phead)
{
    int i = 1;
    node *p, *q;

    scanf("%d", &number);

    p = phead = (node *)malloc(sizeof(node));
    p -> n = i;
    p -> next = NULL;

    for(i = 2; i <= number; i++)
    {
        q = (node *)malloc(sizeof(node));

        q -> n = i;
        p -> next = q;
        p = q;

        if(i == 2)
        {
            temp = q;
        }
    }
    q -> next = phead;

    return phead;
}

void print_linklist(node *phead)
{
    int i;
    node *loop;

    loop = phead;

    for(i = 0; i < number; i++)
    {
        printf("%d\n", loop -> n);
        loop = loop-> next;
    }
}

node *get_linklist(node *phead)
{
    node *pre;
    node *loop;

    pre = phead;
    
    while(1)
    {
        if(pre -> next -> next -> n == temp -> n)
        {
            if(pre -> next -> n == phead -> n)
            {
                phead = phead -> next;
            }

            loop = pre -> next;
            pre -> next = loop -> next; 
            free(loop);
            number--;
            break;
        }
        pre = pre -> next;
    }

    return phead;
}

int main()
{
    node *phead;

    phead = create_linklist(phead);         //创建循环链表
    
    phead = get_linklist(phead);            //寻找temp的前两个结点,并删除

    print_linklist(phead);                  //遍历链表

    return 0;
}
