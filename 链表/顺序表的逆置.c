/*************************************************************************
	> File Name: 顺序表的逆置.c
	> Author: paranoid
	> Mail: www.champion_hengyi@gmail.com
	> Created Time: 2016年09月11日 星期日 15时06分21秒
	> Description: 
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

#define N 10           //线性表可以达到的最大长度

typedef int Elemtype;  //线性表的元素

typedef struct linear_list     //线性表的数据结构
{
    Elemtype n[N];
    int length;
}seqlist;

typedef struct linklist
{
    int n;
    struct linklist *next;
}node;

void init_Seqlist(seqlist *L)
{
    L -> length = 0;
}

void add_Seqlist(seqlist *L)
{
    int i;

    for(i = 0; i < N; i++)
    {
        L -> n[i] = i+1;
    }

    L -> length = N;
}

void reverse_Seqlist(seqlist *L)
{
    int i,j;
    int temp;

    for(i = 0; i < N/2; i++)
    {
        for(j = N-1; j > N/2; j--)
        {
            if(i+j == N-1)
            {
                temp = L -> n[i];
                L -> n[i] = L -> n[j];
                L -> n[j] = temp;
                break;
            }
        }
    }
}

void print_Seqlist(seqlist *L)
{
    int i;

    for(i = 0; i < L -> length; i++)
    {
        printf("%d\n", L -> n[i]);
    }
}

node *create_linklist(seqlist *L)
{
    int i;
    node *phead;
    node *p, *q;

    p = phead = (node *)malloc(sizeof(node));
    phead -> next = NULL;

    for(i = 0; i < L -> length; i++)
    {
        q = (node *)malloc(sizeof(node));

        q -> n = L -> n[i];
        q -> next = p -> next;
        p -> next = q;
        p = q;
    }
    q -> next = NULL;

    return phead;
}

void print_linklist(node *phead)
{
    node *temp;

    for(temp = phead -> next; temp != NULL; temp = temp -> next)
    {
        printf("%d\n", temp -> n);
    }
}

int main()
{
    seqlist L;
    node *phead;

    init_Seqlist(&L);           //初始化线性表

    add_Seqlist(&L);            //给线性表里面添加数据
    
    reverse_Seqlist(&L);        //线性表的逆置

    phead = create_linklist(&L);     //创建链表

    print_Seqlist(&L);          //线性表的显示

    print_linklist(phead);      //链表的显示

    return 0;
}
