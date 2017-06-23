/*************************************************************************
	> File Name: 按规则合并线性单链表.c
	> Author: paranoid
	> Mail: www.champion_hengyi@gmail.com
	> Created Time: 2016年09月14日 星期三 21时12分55秒
	> Description: 
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

typedef struct linklist
{
    int n;
    struct linklist *next;
}node;

typedef struct statlist
{
    node *phead;
    int count;
}attribute_linklist;

attribute_linklist *create_linklist()
{
    int number;
    node *phead, *p, *q;
    attribute_linklist *status;

    status = (attribute_linklist *)malloc(sizeof(attribute_linklist));

    scanf("%d", &number);

    p = phead = (node *)malloc(sizeof(node));
    phead -> next = NULL;

    for(int i = 0; i < number; i++)
    {
        q = (node *)malloc(sizeof(node));
        
        q -> n = i+1;
        p -> next = q;
        p = q;
    }
    q -> next = NULL;

    status -> phead = phead;
    status -> count = number;

    return status;
}

node *combine_linklist(attribute_linklist *status1, attribute_linklist *status2)             //按先A后B的方式合并
{
    node *phead, *p, *q1, *q2;
    node *temp, *loop;

    p = phead = (node *)malloc(sizeof(node));
    phead -> next = NULL;

    temp = status1 -> phead -> next;
    loop = status2 -> phead -> next;

    while(status1->count > status2->count || status1->count == status2->count)
    {
        if(loop == NULL && (status1->count == status2->count))
        {
            q2 -> next = NULL;
            break;
        }
        if(loop == NULL)
            break;

        q1 = (node *)malloc(sizeof(node));                       
        q1 -> n = temp -> n;
        p -> next = q1;
        p = q1;
        temp = temp -> next;

        q2 = (node *)malloc(sizeof(node));
        q2 -> n = loop -> n;
        p -> next = q2;
        p = q2;
        loop = loop -> next;
    }

    while(temp != NULL)
    {
        q1 = (node *)malloc(sizeof(node));

        q1 ->n = temp -> n;
        p -> next = q1;
        p = q1;

        temp = temp -> next;
    }
    q1 -> next = NULL;

    return phead;
}

void print_linklist(node *phead)
{
    node *temp;

    for(temp = phead -> next; temp != NULL; temp = temp -> next)
    {
        printf("%d ", temp -> n);
    }

    printf("\n");
}

int main()
{
    node *phead;
    attribute_linklist *status1, *status2;

    status1 = create_linklist();                      //创建A链表

    status2 = create_linklist();                      //创建B链表

    phead = combine_linklist(status1, status2);       //按规则合并线性单链表

    print_linklist(phead);                            //输出合并后的链表

    return 0;
}
