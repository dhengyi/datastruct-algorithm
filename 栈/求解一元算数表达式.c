/*************************************************************************
	> File Name: 求解一元算数表达式.c
	> Author: paranoid
	> Mail: www.champion_hengyi@gmail.com
	> Created Time: 2016年09月24日 星期六 19时43分46秒
	> Description: 
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define N 100

struct figure_stack                         //操作数栈
{
    double number[N];
    int top;
};

struct symbol_stack                         //操作符栈
{
    char sign[N];
    int top;
};

void enter(char arr[]);

void func(char arr[]);

void push_figstack(struct figure_stack *status, double number);

void push_symstack(struct symbol_stack *status, char sign);

char top_symstack(struct symbol_stack *status);

void pop_figstack(struct figure_stack *status);

void pop_symstack(struct symbol_stack *status);

void add(struct figure_stack *status);

void cut(struct figure_stack *status);

void multiply(struct figure_stack *status);

void divided(struct figure_stack *status);

void enter(char arr[])                      //输入函数
{
    scanf("%s", arr);

    for(int i = 0; i < strlen(arr); i++)
    {
        if(arr[i] != '+' && arr[i] != '-' && arr[i] != '*' && arr[i] != '/' && arr[i] != '(' && arr[i] != ')' && arr[i] != '#' && arr[i] != '.')
        {
            if(arr[i] < '0' || arr[i] > '9')
            {
                printf("您的输入有误，请重新启动程序～～\n");
                exit(1);
            }
        }
    }

    arr[strlen(arr)+1] = '\0';
    arr[strlen(arr)] = '#';
}

void push_figstack(struct figure_stack *status, double number)     //入数字栈
{
    if(status -> top == N-1)
    {
        printf("数字栈已满～～\n");
        return ;
    }

    status -> top++;
    status -> number[status -> top] = number;
}

void push_symstack(struct symbol_stack *status, char sign)         //入操作符栈
{
    if(status -> top == N-1)
    {
        printf("操作符栈已满～～\n");
        return ;
    }

    status -> top++;
    status -> sign[status -> top] = sign;
}

char top_symstack(struct symbol_stack *status)                     //取操作符栈顶元素
{
    char sign;

    sign = status -> sign[status -> top];

    return sign;
}

void pop_figstack(struct figure_stack *status)                     //将数字栈顶部元素弹出
{
    if(status -> top == -1)
    {
        printf("数字栈空～～\n");
        return ;
    }
    status -> top--;
}

void pop_symstack(struct symbol_stack *status)                     //将操作符栈顶部元素弹出
{
    status -> top--;
}

void add(struct figure_stack *status)                              //加法运算
{
    float number;

    number = status -> number[status -> top -1] + status -> number[status -> top];

    pop_figstack(status);
    pop_figstack(status);
    push_figstack(status, number);
}

void cut(struct figure_stack *status)                              //减法运算
{
    float number;

    number = status -> number[status -> top -1] - status -> number[status -> top];

    pop_figstack(status);
    pop_figstack(status);
    push_figstack(status, number);
}

void multiply(struct figure_stack *status)                         //乘法运算
{
    float number;

    number = status -> number[status -> top -1] * status -> number[status -> top];

    pop_figstack(status);
    pop_figstack(status);
    push_figstack(status, number);
}

void divided(struct figure_stack *status)                          //除法运算
{
    float number;

    number = status -> number[status -> top -1] / status -> number[status -> top];

    pop_figstack(status);
    pop_figstack(status);
    push_figstack(status, number);
}

void func(char arr[])
{
    int i = 0, j = 0;
    int temp, loop;
    float number;
    char sign;
    struct figure_stack status1;
    struct symbol_stack status2;

    status1.top = -1;
    status2.top = -1;
    status2.top++;
    status2.sign[status2.top] = '#';

    while(i < strlen(arr))
    {
        if(arr[i] >= '0' && arr[i] <= '9')
        {
            while((arr[i] >= '0' && arr[i] <= '9') || arr[i] == '.')
            {
                i++;
            }

            if(arr[i] == '-')
            {
                temp = arr[i]-2;
            }

            if(arr[i] == '+')
            {
                temp = arr[i];
            }

            if(arr[i] == '/')
            {
                temp = arr[i];
            }

            if(arr[i] == '*')
            {
                temp = arr[i]+5;
            }

            if(arr[i] == '#')
            {
                temp = arr[i];
            }

            number = atof(&arr[j]);                  //将字符数字转换为数字
            push_figstack(&status1, number);         //将数字压入数字栈
            j = i;
        }
        else
        {
            sign = top_symstack(&status2);           //取操作符栈顶元素
            loop = sign;

            if(sign == '*')
            {
                loop += 5;
            }

            if(sign == '-')
            {
                loop -= 2;
            }

            if(sign == '#' && arr[j] == '#')
            {
                printf("结果：%.2f\n", status1.number[status1.top]);
                exit(0);
            }

            if(temp > loop)
            {
                push_symstack(&status2, arr[j]);     //将操作符压入操作符栈
                i++;
                j = i;
                continue;
            }

            if(temp <= loop)
            {
                pop_symstack(&status2);
                switch(sign)
                {
                    case '+':
                        add(&status1);
                    break;

                    case '-':
                        cut(&status1);
                    break;

                    case '*':
                        multiply(&status1);
                    break;

                    case '/':
                        divided(&status1);
                    break;
                }  
            }
        }        
    }
}

int main()
{
    int number;
    char arr[N];

    enter(arr);                    //输入函数

    func(arr);                     //功能函数（求解的过程)

    return 0;
}
