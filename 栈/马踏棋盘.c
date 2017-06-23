/*************************************************************************
	> File Name: 马踏棋盘.c
	> Author: paranoid
	> Mail: www.champion_hengyi@gmail.com
	> Created Time: 2016年09月29日 星期四 19时22分41秒
	> Description: 
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

#define N 8
#define SIZE 100

struct stack                        //马踏棋盘的栈
{
    int arr[SIZE];
    int top;
};

int count = 0;

void init_board(int chessboard[][N]);

void init_mystack(struct stack *status);

void init_place(int *x, int *y, int chessboard[][N]);

void push_stack(int x, int y, struct stack *status);

void top_stack(int *x, int *y, struct stack *status);

void pop_stack(struct stack *status);

void run(int chessboard[][N], struct stack *status);

void init_board(int chessboard[][N])                        //初始化棋盘
{
    int i, j;

    for(i = 0; i < N; i++)
    {
        for(j = 0; j < N; j++)
        {
            chessboard[i][j] = 0;
        }
    }
}

void init_mystack(struct stack *status)                                           //初始化栈
{
    status -> top = -1;
}

void push_stack(int x, int y, struct stack *status)                               //入栈
{
    int number;
    number = x*10+y;

    if(status -> top == SIZE-1)
    {
        printf("栈已满～～\n");
        exit(1);
    }
    status -> top++;
    status -> arr[status -> top] = number;
    
    if(x == 0)
    {
        printf("0%d       ", status -> arr[status -> top]);
    }
    else
    {
        printf("%d       ", status -> arr[status -> top]);
    }
    count++;
    if(count % 8 == 0)
    {
        printf("\n");
    }
}

void top_stack(int *x, int *y, struct stack *status)
{
    *x = status -> arr[status -> top] / 10;
    *y = status -> arr[status -> top] % 10;
}

void pop_stack(struct stack *status)                                              //出栈
{
    if(status -> top == -1)
    {
        printf("栈已空～～\n");
        exit(1);
    }

    status -> top--;
}

void init_place(int *x, int *y, int chessboard[][N])                              //初始化输入
{
    scanf("%d %d", x, y);

    if(*x < 0 || *x > 8 || *y < 0 || *y > 8)
    {
        printf("您的输入有误，请重新登录程序～～\n");
        exit(1);
    }

    chessboard[*x][*y] = 1;
}

void run(int chessboard[][N], struct stack *status)               //马踏棋盘
{
    int x, y;

    while(status -> top != -1)
    {
        top_stack(&x, &y, status);                                //将栈中的顶部元素提取出来，并分解

        if(x-2 >= 0 && x-2 <= 7 && y+1 >= 0 && y+1 <= 7 && chessboard[x-2][y+1] != 1)
        {
            chessboard[x-2][y+1] = 1;
            push_stack(x-2, y+1, status);
            continue;
        }

        if(x-1 >= 0 && x-1 <= 7 && y+2 >= 0 && y+2 <= 7 && chessboard[x-1][y+2] != 1)
        {
            chessboard[x-1][y+2] = 1;
            push_stack(x-1, y+2, status);
            continue;
        }

        if(x+1 >= 0 && x+1 <= 7 && y+2 >= 0 && y+2 <= 7 && chessboard[x+1][y+2] != 1)
        {
            chessboard[x+1][y+2] = 1;
            push_stack(x+1, y+2, status);
            continue;
        }

        if(x+2 >= 0 && x+2 <= 7 && y+1 >= 0 && y+1 <= 7 && chessboard[x+2][y+1] != 1)
        {
            chessboard[x+2][y+1] = 1;
            push_stack(x+2, y+1, status);
            continue;
        }

        if(x+2 >= 0 && x+2 <= 7 && y-1 >= 0 && y-1 <= 7 && chessboard[x+2][y-1] != 1)
        {
            chessboard[x+2][y-1] = 1;
            push_stack(x+2, y-1, status);
            continue;
        }

        if(x+1 >= 0 && x+1 <= 7 && y-2 >= 0 && y-2 <= 7 && chessboard[x+1][y-2] != 1)
        {
            chessboard[x+1][y-2] = 1;
            push_stack(x+1, y-2, status);
            continue;
        }

        if(x-1 >= 0 && x-1 <= 7 && y-2 >= 0 && y-2 <= 7 && chessboard[x-1][y-2] != 1)
        {
            chessboard[x-1][y-2] = 1;
            push_stack(x-1, y-2, status);
            continue;
        }

        if(x-2 >= 0 && x-2 <= 7 && y-1 >= 0 && y-1 <= 7 && chessboard[x-2][y-1] != 1)
        {
            chessboard[x-2][y-1] = 1;
            push_stack(x-2, y-1, status);
            continue;
        }

        pop_stack(status);
    }
}

int main()
{
    int chessboard[N][N];                              //棋盘
    int x, y;
    struct stack status;                               //存储马走的路线的栈

    init_board(chessboard);                            //初始化棋盘

    init_mystack(&status);                             //初始化栈

    init_place(&x, &y, chessboard);                    //初始化位置

    push_stack(x, y, &status);                         //将初始化位置压入栈中

    run(chessboard, &status);                          //马踏棋盘

    return 0;
}
