/*************************************************************************
	> File Name: （链表）冒泡排序.c
	> Author: 
	> Mail: 
	> Created Time: 2016年08月04日 星期四 16时13分48秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int a;
    struct node * next;
}Node;

Node * Create(Node * phead)
{
    Node * p, * q;
    int i = 0;
    int count = 0;

    phead = (Node *)malloc(sizeof(Node));
    phead -> next = NULL; // 创建一个头节点
    p = phead;

    scanf("%d", &count);

    if(count <= 0)
    {
        phead -> next == NULL;
        return NULL;
    }

    while(i++ < count)
    {
        q = (Node *)malloc(sizeof(Node));
        scanf("%d", &q -> a);

        q -> next = NULL;
        p -> next = q;
        p = q;
    }

    return phead;
}

Node * Show(Node * phead)
{
    if(phead -> next == NULL)
    {
        return NULL;
    }

    Node * temp;
    temp = phead -> next;

    while(temp != NULL)
    {
        printf("%d\n", temp -> a);
        temp = temp -> next;
    }

    return phead;
}

Node * Sort(Node * phead)
{
    Node * i, * j; 

    for(i = phead; i -> next -> next != NULL; i = i -> next)
    {
        for(j = phead; j -> next ->next != NULL; j = j -> next)
        {
            if( j-> next -> a > j->next -> next ->a )
            {
                Node * a, * b, * c;
                a = j -> next;
                b = a -> next;
                c = b -> next;

                j -> next = b;
                b -> next = a;
                a -> next = c;
                //b -> next = a;
            }
        }
    }

    return phead;
}

int main()
{
    Node * phead = NULL;

    phead = Create(phead); // 链表的创建

    phead = Sort(phead); // 链表的排序

    Show(phead); // 链表的显示

    return 0;
}
