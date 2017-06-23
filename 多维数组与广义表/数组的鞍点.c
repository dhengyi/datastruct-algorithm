/*************************************************************************
	> File Name: 数组的鞍点.c
	> Author: paranoid
	> Mail: www.champion_hengyi@gmail.com
	> Created Time: 2016年10月23日 星期日 16时22分20秒
	> Description: 
 ************************************************************************/

#include<stdio.h>

#define N 5

int main()
{
    int array[N][N];
    int i, j, k;
    int temp, loop;

    for(i = 0; i < N; i++)
    {
        for(j = 0; j < N; j++)
        {
            scanf("%d", &array[i][j]);
        }
    }

    for(i = 0; i < N; i++)
    {
        j = 0;
        temp = array[i][j];

        for(; j < N; j++)
        {
            if(temp >= array[i][j])
            {
                temp = array[i][j];
            }
            else
            {
                temp = temp;
            }
        }

        for(j = 0; j < N; j++)
        {
            if(temp == array[i][j])
            {
                break;
            }
        }

        loop = temp;
        for(k = 0; k < N; k++)
        {
            if(loop >= array[k][j])
            {
                loop = loop;
            }
            else
            {
                loop = array[k][j];
            }
        }

        if(temp == loop)
        {
            for(k = 0; k < N; k++)
            {
                if(loop == array[k][j])
                {
                    printf("%d %d %d\n", k, j, loop);
                }
            }
        }
    }

    return 0;
}
