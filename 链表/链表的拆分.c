/*************************************************************************
	> File Name: 链表的拆分.c
	> Author: paranoid
	> Mail: www.champion_hengyi@gmail.com
	> Created Time: 2016年09月11日 星期日 21时12分34秒
	> Description: 
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

typedef struct linklist
{
    int n;
    struct linklist *next;
}node;

typedef struct part_linklist
{
    node *p;
    node *q;
}separate;

node *create_partlist(node *phead, node *temp);

node *create_linklist(node *phead)
{
    int n;
    node *p, *q;
    
    p = phead = (node*)malloc(sizeof(node));
    phead -> next = NULL;

    scanf("%d", &n);

    for(int i = 0; i < n; i++)
    {
        q = (node*)malloc(sizeof(node));
        scanf("%d", &q -> n);

        q -> next = NULL;
        p -> next = q;
        p = q;
    }

    return phead;
}

node *sort_linklist(node *phead)
{
    node *p, *q;
    node *temp, *loop;

    if(phead -> next == NULL || phead == NULL)                       //判断链表只有一个节点还是只有头节点
    {
        return phead;
    }
    
    for(temp = phead -> next; temp != NULL; temp = temp -> next)
    {
        printf("~~~: %d\n", temp -> n);
    }

    while(p != phead -> next)
    {
        for(q = phead; q -> next -> next != NULL; q = q -> next)
        {
            if(q->next->n > q->next->next->n)
            {
                temp = q -> next;
                loop = q -> next -> next;
                q -> next = loop;
                temp -> next = loop -> next;
                loop -> next = temp;
            }
        }
        p = loop;
    }

    return phead;
}

separate *part_linklist(node *phead)
{
    node *phead1, *phead2;
    node *temp, *loop;
    separate *status;

    phead1 = (node *)malloc(sizeof(node));
    phead2 = (node *)malloc(sizeof(node));

    phead1 -> next = NULL;
    phead2 -> next = NULL;

    for(temp = phead -> next; temp != NULL; temp = temp -> next)
    {
        if(temp->n % 2 != 0)
        {
            loop = (node *)malloc(sizeof(node));
            loop -> n = temp -> n;
            loop -> next = NULL;
            phead1 = create_partlist(phead1, loop);
        }
        else
        {
            loop = (node *)malloc(sizeof(node));
            loop -> n = temp -> n;
            loop -> next = NULL;
            phead2 = create_partlist(phead2, loop);
        }
    }

    status -> p = phead1;
    status -> q = phead2;
    
    return status;
}

node *create_partlist(node *phead, node *temp)
{
    node *loop;

    if(temp->n % 2 != 0)
    {
        for(loop = phead; loop -> next != NULL; loop = loop -> next);
        
        loop -> next = temp;

        return phead;
    }
    else
    {
        for(loop = phead; loop -> next != NULL; loop = loop -> next);

        loop -> next = temp;

        return phead;
    }
}

void print_linklist(separate *status)
{
    node *temp;
    
    for(temp = status -> p -> next; temp != NULL; temp = temp -> next)
    {
        printf("%d ", temp -> n);
    }

    printf("\n");

    for(temp = status -> q -> next; temp != NULL; temp = temp -> next)
    {
        printf("%d ", temp -> n);
    }

    printf("\n");
}

int main()
{
    node *phead;
    separate *status;

    phead = create_linklist(phead);           //创建链表

    phead = sort_linklist(phead);             //对链表进行排序

    status = part_linklist(phead);            //对排序好的链表进行拆分

    print_linklist(status);                   //输出拆分链表
}
