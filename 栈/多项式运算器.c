/*************************************************************************
	> File Name: 多项式运算器.c
	> Author: paranoid
	> Mail: www.champion_hengyi@gmail.com
	> Created Time: 2016年09月18日 星期日 16时34分08秒
	> Description: 
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define N 1000
#define MAXSIZE 1000

typedef struct linklist
{
    float coef;                            //系数
    int expn;                              //指数
    int count;                             //结点数
    struct linklist *next;
}node;

void interface();

void select_interface(char n[]);

void func(int number);

node *create_linklist();

void buttle_sort(node *arr[], int number);

node *sum(node *arr[], int number);

void print_polyn(node *over);

void add();

node *minus(node *arr[], int number);

void cut();

node *mount(node *arr[], int number);

void multiply();

node *merge(node *over);

void derivative();

void interface()                                         //界面
{
    printf("1.求和                                  2.求差\n");
    printf("3.乘积                                  4.求导\n");
    printf("请输入要操作的选项：\n");
}

void select_interface(char n[])                          //界面选择
{
    while(1)
    {
        memset(n, 0, sizeof(N));
        scanf("%s", n);

        if((n[0] < '1') || (n[0] > '4') || strlen(n) != 1)
        { 
            printf("您的输入有误，请重新输入\n");
        }
        else
        {
            break;
        }
    }
}

void func(int number)                                    //功能的实现
{
    switch(number)
    {
        case 1:
            add();                                       //多项式求和
        break;

        case 2:
            cut();                                       //多项式求差
        break;

        case 3:
            multiply();                                  //多项式乘积
        break;

        case 4:
            derivative();                                //求导
        break;
    }
}

node *create_linklist()                                  //创建多项式     
{
    int number;
    int i;
    node *phead, *p, *q;

    p = phead = (node *)malloc(sizeof(node));
    phead -> next = NULL;

    printf("请输入多项式的项数：\n");
    if((scanf("%d", &number) != 1))
    {
        printf("您的输入有误，请重新开启运算器～～\n");
        exit(0);
    }

    phead -> count = number;

    printf("请依次输入要进行运算的多项式的每个项的系数和指数：\n");
    for(i = 0; i < number; i++)
    {
        q = (node *)malloc(sizeof(node));

        scanf("%f", &q -> coef);
        scanf("%d", &q -> expn);
        q -> next = NULL;
        p -> next = q;
        p = q;
    }

    return phead;
}

void buttle_sort(node *arr[], int number)                                        //排序
{
    int i, j;
    node *phead;
    node *temp, *loop;
    node *p, *q;

    for(i = 0; i < number; i++)
    {
        phead = arr[i];

        if(phead -> next == NULL || phead == NULL)
        {
            return ;
        }

        for(j = 0; j <= (phead -> count); j++)                                     //对多项式进行冒泡排序
        {
            for(q = phead; q -> next -> next != NULL; q = q -> next)
            {
                if(q->next->expn > q->next->next->expn)
                {
                    temp = q -> next;
                    loop = q -> next -> next;
                    q -> next = loop;
                    temp -> next =  loop -> next;
                    loop -> next = temp;
                }
            }
        }
    }
}

node *merge(node *over)                                      //同类项的合并
{
    node *arr[1];
    node *temp, *loop, *tmp;

    arr[0] = over;
    temp = over -> next;
    loop = temp -> next;

    buttle_sort(arr, 1);                                     //对运算后的多项式进行排序
    
    temp = over -> next;
    loop = temp -> next;

    print_polyn(arr[0]);

    while(loop != NULL)
    {
        if(temp -> expn == loop -> expn)
        {
            tmp = loop;
            temp -> coef += loop -> coef;
            temp -> next = loop -> next;
            loop = temp -> next;
            free(tmp);
        }
        else
        {
            temp = temp -> next;
            loop = temp -> next;
        }
    }

    return over;
}

node *sum(node *arr[], int number)                    //求和
{
    int i = 0;
    node *phead;
    node *p, *q, *over, *temp, *ovr;

    p = arr[i] -> next;
    for(i = 1; i < number; i++)
    {
        ovr = over = (node *)malloc(sizeof(node));    //存储多项式的和
        ovr -> count = 0;
        over -> next = NULL;

        q = arr[i] -> next;
        while(p != NULL && q != NULL)                 //对两个多项式进行扫描
        {
            temp = (node *)malloc(sizeof(node));

            if(p -> expn < q -> expn)
            {
                temp -> coef = p -> coef;
                temp -> expn = p -> expn;
                p = p -> next;
            } 
            else if(p -> expn > q -> expn)
            {
                temp -> coef = q -> coef;
                temp -> expn = q -> expn;
                q = q -> next;
            }
            else
            {
                temp -> coef = p -> coef + q -> coef;
                temp -> expn = p -> expn;
                p = p -> next;
                q = q -> next;
            }

            ovr -> count++;
            temp -> next = NULL;
            ovr -> next = temp;
            ovr = temp;
        }
        
        while(p != NULL)                              //p中有剩余项，将剩余项插入到over中 
        {
            temp = (node *)malloc(sizeof(node));
            temp -> coef = p -> coef;
            temp -> expn = p -> expn;
            ovr -> count++;
            p = p -> next;
            temp -> next = NULL;
            ovr -> next = temp;
            ovr = temp;
            
        }

        while(q != NULL)                                  //q中有剩余项，将剩余项插入到over中
        {
            temp = (node *)malloc(sizeof(node));
            temp -> coef = q -> coef;
            temp -> expn = q -> expn;
            ovr -> count++;
            q = q -> next;
            temp -> next = NULL;
            ovr -> next = temp;
            ovr = temp;
        }

        p = over -> next;
    }

    over = merge(over);                                   //对运算后的多项式进行合并同类项

    return over;
}

void print_polyn(node *over)                              //输出
{
    int i;
    node *temp;

    printf("结果：");
    for(temp = over -> next; temp != NULL; temp = temp -> next)
    {
        if(temp -> coef == 0)                             //如果多项式的系数为0,则直接将这个项进行跳过
        {
            temp = temp -> next;
        }

        if(temp -> expn == 0)                             //如果指数为0,控制输出格式
        {
            if(temp -> next != NULL)
            {
                if(temp -> next -> coef < 0)
                {
                    printf("%.2f", temp -> coef);
                }
                else
                {
                    printf("%.2f+", temp -> coef);
                }
            }
            else if(temp -> next == NULL)
            {
                printf("%.2f", temp -> coef);
                break;
            }

            temp = temp -> next;
        }
            
        if(temp -> next != NULL)                          //指数不为0的时候输出格式
        {
            if(temp -> next -> coef < 0)
            {
                printf("%.2fX^%d", temp -> coef, temp -> expn);
            }
            else
            {
                printf("%.2fX^%d+", temp -> coef, temp -> expn);
            }
        }
        else
        {
            printf("%.2fX^%d", temp -> coef, temp -> expn);
        }
    }
    printf("\n");
}

void add()                                               //求和前的准备
{
    int number;
    int i;
    node *arr[N];
    node *over;

    printf("请输入要求和多项式的个数：\n");
    if((scanf("%d", &number) != 1))
    {
        printf("您的输入有误，请重新开启运算器～～\n");
        exit(0);
    }

    for(i = 0; i < number; i++)
    {
        arr[i] = create_linklist();                      //创建多项式
    }

    buttle_sort(arr, number);                            //对输入的多项式按指数进行升序排序

    over = sum(arr, number);                             //对多项式进行求和

    print_polyn(over);                                   //对排序好的多项式进行输出
}

node *minus(node *arr[], int number)                     //求差
{
    int i = 0;
    node *phead;
    node *p, *q, *over, *temp, *ovr;

    p = arr[i] -> next;
    for(i = 1; i < number; i++)
    {
        ovr = over = (node *)malloc(sizeof(node));    //存储多项式的和差
        ovr -> count = 0;
        over -> next = NULL;

        q = arr[i] -> next;
        while(p != NULL && q != NULL)                 //对两个多项式进行扫描
        {
            temp = (node *)malloc(sizeof(node));

            if(p -> expn < q -> expn)
            {
                temp -> coef = p -> coef;
                temp -> expn = p -> expn;
                p = p -> next;
            } 
            else if(p -> expn > q -> expn)
            {
                temp -> coef = q -> coef*(-1);
                temp -> expn = q -> expn;
                q = q -> next;
            }
            else
            {
                temp -> coef = p -> coef - q -> coef;
                temp -> expn = p -> expn;
                p = p -> next;
                q = q -> next;
            }

            ovr -> count++;
            temp -> next = NULL;
            ovr -> next = temp;
            ovr = temp;
        }
        
        while(p != NULL)                              //p中有剩余项，将剩余项插入到over中 
        {
            temp = (node *)malloc(sizeof(node));
            temp -> coef = p -> coef;
            temp -> expn = p -> expn;
            ovr -> count++;
            p = p -> next;
            temp -> next = NULL;
            ovr -> next = temp;
            ovr = temp;
        }

        while(q != NULL)                              //q中有剩余项，将剩余项插入到over中
        {
            temp = (node *)malloc(sizeof(node));
            temp -> coef = q -> coef*(-1);
            temp -> expn = q -> expn;
            ovr -> count++;
            q = q -> next;
            temp -> next = NULL;
            ovr -> next = temp;
            ovr = temp;
        }

        p = over -> next;
    }

    over = merge(over);

    return over;
}

void cut()                                               //求差前的准备
{
    int number;
    int i;
    node *arr[N];
    node *over;

    printf("请输入要求差多项式的个数：\n");
    if((scanf("%d", &number) != 1))
    {
        printf("您的输入有误，请重新开启运算器～～\n");
        exit(0);
    }

    for(i = 0; i < number; i++)
    {
        arr[i] = create_linklist();
    }

    buttle_sort(arr, number);

    over = minus(arr, number);                           //对多项式进行求差

    print_polyn(over);                                   
}

node *mount(node *arr[], int number)                  //求积
{
     int i = 0;
    node *phead;
    node *p, *q, *over, *temp, *ovr;

    p = arr[i] -> next;
    for(i = 1; i < number; i++)
    {
        ovr = over = (node *)malloc(sizeof(node));    //存储多项式的积
        ovr -> count = 0;
        over -> next = NULL;

        q = arr[i] -> next;
        while(p != NULL)                              //对两个多项式进行扫描
        {
            while(q != NULL)
            {
                temp = (node *)malloc(sizeof(node));
                temp -> coef = p -> coef * q -> coef;
                temp -> expn = p -> expn + q -> expn;
                ovr -> count++;
                q = q -> next;
                temp -> next = NULL;
                ovr -> next = temp;
                ovr = temp;
            }
            p = p -> next;
            q = arr[i] -> next;
        }
        p = over -> next;
    }

    over = merge(over);

    return over;
}

void multiply()                                       //求积前的准备
{
    int number;
    int i;
    node *arr[N];
    node *over;

    printf("请输入要求积多项式的个数：\n");
    if((scanf("%d", &number) != 1))
    {
        printf("您的输入有误，请重新开启运算器～～\n");
        exit(0);
    }

    for(i = 0; i < number; i++)
    {
        arr[i] = create_linklist();
    }

    buttle_sort(arr, number);

    over = mount(arr, number);                           //对多项式进行乘积

    print_polyn(over);
}

void derivative()                                        //求导
{
    node *phead;
    node *temp;
    node *arr[1];

    phead = create_linklist();

    arr[0] = phead;

    buttle_sort(arr, 1);

    for(temp = phead -> next; temp != NULL; temp = temp -> next)
    {
        if(temp -> expn == 0)
        {
            temp -> coef = 0;
        }
        else if(temp -> expn == 1)
        {
            temp -> expn = 0;
        }
        else
        {
            temp -> coef *= temp -> expn;
            temp -> expn -= 1;
        }
    }

    print_polyn(phead);
}

int main()
{
    int number;
    char n[N];

    interface();                           //主界面

    select_interface(n);                   //选项

    number = atoi(n);

    func(number);                          //功能实现函数

    return 0;
}
