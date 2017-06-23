/*************************************************************************
	> File Name: 稀疏矩阵的运算.c
	> Author: paranoid
	> Mail: www.champion_hengyi@gmail.com
	> Created Time: 2016年10月14日 星期五 08时10分12秒
	> Description: 
 ************************************************************************/

#include<stdio.h>

#define MAXSIZE 100

typedef struct
{
    int row, col;
    int value;
}Tripe;

typedef struct                                  //三元表的存储结构
{
    Tripe data[MAXSIZE+1];
    int row, col, nums;
}TSMatrix;

void interface();

void select();

void init_TSMatrix(TSMatrix *list1, TSMatrix *list2, int number);

void add(TSMatrix list1, TSMatrix list2, TSMatrix *list3);

void minus(TSMatrix list1, TSMatrix list2, TSMatrix *list3);

void multiply(TSMatrix list1, TSMatrix list2, TSMatrix *list3);

void reserve(TSMatrix list1, TSMatrix *list3);

void print_TSMatrix(TSMatrix list3);

void interface()                                                 //主界面
{
    printf("1.加法                     2.减法\n");
    printf("3.乘法                     4.转置\n");
    printf("请输入您要操作的选项：\n");
}

void select()                                                    //选项
{
    int number;
    TSMatrix list1, list2, list3;

    scanf("%d", &number);

    init_TSMatrix(&list1, &list2, number);                       //初始化输入三元表

    switch(number)
    {
        case 1:
            add(list1, list2, &list3);
        break;

        case 2:
            minus(list1, list2, &list3);
        break;

        case 3:
            multiply(list1, list2, &list3);
        break;

        case 4:
            reserve(list1, &list3);
        break;
    }

    print_TSMatrix(list3);                                       //对运算后的矩阵进行输出
}

void init_TSMatrix(TSMatrix *list1, TSMatrix *list2, int number) //初始化输入三元表
{
    if(number != 4)
    {
        printf("请输入第一个稀疏矩阵的非零数据个数, 行数，列数：\n");
        scanf("%d %d %d", &list1 -> nums, &list1 -> row, &list1 -> col);

        printf("请输入第一个稀疏矩阵的数据元素：\n");
        for(int i = 1; i <= list1 -> nums; i++)
        {
            scanf("%d %d %d", &list1 -> data[i].row, &list1 -> data[i].col, &list1 -> data[i].value);
        }

        printf("请输入第二个稀疏矩阵的非零数据个数，行数，列数：\n");
        scanf("%d %d %d", &list2 -> nums, &list2 -> row, &list2 -> col);

        printf("请输入第二个稀疏矩阵的数据元素：\n");
        for(int i = 1; i <= list2 -> nums; i++)
        {
            scanf("%d %d %d", &list2 -> data[i].row, &list2 -> data[i].col, &list2 -> data[i].value);
        }
    }
    else
    {
        printf("请输入要进行转置的矩阵的非零元素的个数，行数，列数：\n");
        scanf("%d %d %d", &list1 -> nums, &list1 -> row, &list1 -> col);

        printf("请输入要进行转置矩阵的数据元素：\n");
        for(int i = 1; i <= list1 -> nums; i++)
        {
            scanf("%d %d %d", &list1 -> data[i].row, &list1 -> data[i].col, &list1 -> data[i].value);
        }
    }
}

void add(TSMatrix list1, TSMatrix list2, TSMatrix *list3)        //对稀疏矩阵的加法
{
    int i = 1, j = 1, k;
    list3 -> nums = list1.nums;
    list3 -> row = list1.row;
    list3 -> col = list1.col;

    for(k = 1; k <= list1.nums + list2.nums; k++)
    {
        if(j > list2.nums)
        {
            list3 -> data[k].row = list1.data[i].row;
            list3 -> data[k].col = list1.data[i].col;
            list3 -> data[k].value = list1.data[i].value;
            i++;
            continue;
        }

        if(i > list1.nums)
        {
            list3 -> data[k].row = list2.data[j].row;
            list3 -> data[k].col = list2.data[j].col;
            list3 -> data[k].value = list2.data[j].value;
            j++;
            continue;
        }

        if((list1.data[i].row < list2.data[j].row) || (list1.data[i].row == list2.data[j].row && list1.data[i].col < list2.data[j].col))
        {
            list3 -> data[k].row = list1.data[i].row;
            list3 -> data[k].col = list1.data[i].col;
            list3 -> data[k].value = list1.data[i].value;
            i++;
            continue;
        }

        if((list1.data[i].row > list2.data[j].row) || (list1.data[i].row == list2.data[j].row && list1.data[i].col > list2.data[j].col))
        {
            list3 -> data[k].row = list2.data[j].row;
            list3 -> data[k].col = list2.data[j].col;
            list3 -> data[k].value = list2.data[j].value;
            j++;
            continue;
        }

        if(list1.data[i].row == list2.data[j].row && list1.data[i].col == list2.data[j].col)
        {
            list3 -> data[k].row = list1.data[i].row;
            list3 -> data[k].col = list1.data[i].col;
            list3 -> data[k].value = list1.data[i].value + list2.data[j].value;
            i++;
            j++;
            continue;
        }
    }
}

void minus(TSMatrix list1, TSMatrix list2, TSMatrix *list3)      //对稀疏矩阵的减法     
{
    int i = 1, j = 1, k;
    list3 -> nums = list1.nums;
    list3 -> row = list1.row;
    list3 -> col = list1.col;

    for(k = 1; k <= list1.nums + list2.nums; k++)
    {
        if(j > list2.nums)
        {
            list3 -> data[k].row = list1.data[i].row;
            list3 -> data[k].col = list1.data[i].col;
            list3 -> data[k].value = list1.data[i].value;
            i++;
            continue;
        }

        if(i > list1.nums)
        {
            list3 -> data[k].row = list2.data[j].row;
            list3 -> data[k].col = list2.data[j].col;
            list3 -> data[k].value = list2.data[j].value;
            j++;
            continue;
        }

        if((list1.data[i].row < list2.data[j].row) || (list1.data[i].row == list2.data[j].row && list1.data[i].col < list2.data[j].col))
        {
            list3 -> data[k].row = list1.data[i].row;
            list3 -> data[k].col = list1.data[i].col;
            list3 -> data[k].value = list1.data[i].value;
            i++;
            continue;
        }

        if((list1.data[i].row > list2.data[j].row) || (list1.data[i].row == list2.data[j].row && list1.data[i].col > list2.data[j].col))
        {
            list3 -> data[k].row = list2.data[j].row;
            list3 -> data[k].col = list2.data[j].col;
            list3 -> data[k].value = list2.data[j].value;
            j++;
            continue;
        }

        if(list1.data[i].row == list2.data[j].row && list1.data[i].col == list2.data[j].col)
        {
            list3 -> data[k].row = list1.data[i].row;
            list3 -> data[k].col = list1.data[i].col;
            list3 -> data[k].value = list1.data[i].value - list2.data[j].value;
            i++;
            j++;
            continue;
        }
    }
}

void multiply(TSMatrix list1, TSMatrix list2, TSMatrix *list3)   //对稀疏矩阵的乘法
{
    int k = 1;
    int sum;
    int list1_array[list1.row +1][list1.col +1];
    int list2_array[list2.row +1][list2.col +1];

    list3 -> row = list1.row;
    list3 -> col = list2.col;

    for(int i = 1; i <= list1.row; i++)
    {
        for(int j = 1; j <= list1.col; j++)
        {
            if(i == list1.data[k].row && j == list1.data[k].col)
            {
                list1_array[i][j] = list1.data[k].value;
                k++;
            }
            else
            {
                list1_array[i][j] = 0;
            }
        }
    }

    for(int i = 1; i <= list1.row; i++)
    {
        for(int j = 1; j <= list1.col; j++)
        {
            printf("%d ", list1_array[i][j]);
        }
        printf("\n");
    }

    k = 1;
    for(int i = 1; i <= list2.row; i++)
    {
        for(int j = 1; j <= list2.col; j++)
        {
            if(i == list2.data[k].row && j == list2.data[k].col)
            {
                list2_array[i][j] = list2.data[k].value;
                k++;
            }
            else
            {
                list2_array[i][j] = 0;
            }
        }
    }

    for(int i = 1; i <= list2.row; i++)
    {
        for(int j = 1; j <= list2.col; j++)
        {
            printf("%d ", list2_array[i][j]);
        }
        printf("\n");
    }

    k = 1;
    for(int p = 1; p <= list1.row; p++)
    {
        for(int i = 1; i <= list2.col; i++)
        {
            sum = 0;
            for(int j = 1; j <= list2.row; j++)
            {
                sum += list1_array[p][j] * list2_array[j][i];
            }

            printf("%d\n", sum);

            if(sum != 0)
            {
                list3 -> data[k].row = p;
                list3 -> data[k].col = i;
                list3 -> data[k].value = sum;
                list3 -> nums = k;
                k++;
            }
        }
    }
}

void reserve(TSMatrix list1, TSMatrix *list3)                     //矩阵的转置
{
    Tripe data;

    list3 -> row = list1.col;
    list3 -> col = list1.row;
    list3 -> nums = list1.nums;

    for(int i = 1; i <= list1.nums; i++)
    {
        list3 -> data[i].row = list1.data[i].col;
        list3 -> data[i].col = list1.data[i].row;
        list3 -> data[i].value = list1.data[i].value;
    }

    for(int i = 1; i <= list3 -> nums; i++)
    {
        for(int j = 1; j < list3 -> nums; j++)
        {
            if(list3 -> data[j].row >= list3 -> data[j+1].row)
            {
                data = list3 -> data[j];
                list3 -> data[j] = list3 -> data[j+1];
                list3 -> data[j+1] = data;
            }
        }
    }

    for(int i = 1; i <= list3 -> nums; i++)
    {
        for(int j = 1; j <= list3 -> nums; j++)
        {
            if(list3 -> data[j].row == list3 -> data[j+1].row && list3 -> data[j].col >= list3 -> data[j+1].col)
            {
                data = list3 -> data[j];
                list3 -> data[j] = list3 -> data[j+1];
                list3 -> data[j+1] = data;
            }
        }
    }

    for(int i = 1; i <= list3 -> nums; i++)
    {
        printf("%d %d %d\n", list3 -> data[i].row, list3 -> data[i].col, list3 -> data[i].value);
    }
}

void print_TSMatrix(TSMatrix list3)                              //对运算后的矩阵进行输出
{
    int k = 1;
    int array[list3.row][list3.col];

    for(int i = 1; i <= list3.row; i++)
    {
        for(int  j = 1; j <= list3.col; j++)
        {
            if(i == list3.data[k].row && j == list3.data[k].col)
            {
                array[i][j] = list3.data[k].value;
                k++;
            }
            else
            {
                array[i][j] = 0;
            }
        }
    }

    for(int i = 1; i <= list3.row; i++)
    {
        for(int j = 1; j <= list3.col; j++)
        {
            printf("%d  ", array[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    interface();                   //主界面

    select();                      //选项
}
