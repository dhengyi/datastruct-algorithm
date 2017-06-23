/*************************************************************************
	> File Name: 哈夫曼树的构造.c
	> Author: Paranoid
	> Mail: championhengyi@gmail.com
	> Created Time: 2016年11月08日 星期二 21时02分07秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define N 100

typedef struct                                     //哈夫曼结点数据结构
{
    float weight;
    char data;
    int parent, lchild, rchild;
}HuffmanCode;

void sele_ct(HuffmanCode huffmancode[], int count, int *s1, int *s2)                    //将最小的两个结点选择出来
{
    int i;

    for(i = 1; i < count; i++)
    {
        if(huffmancode[i].parent == 0 && huffmancode[i+1].parent == 0)
        {
            *s1 = i;
            *s2 = i+1;
            break;
        }
    }
}

void CtrHuffmantree(HuffmanCode huffmancode[], int leaves_code, int code_count)        //构造哈夫曼树
{
    int i, j;
    int loop;
    int s1, s2;
    HuffmanCode temp;

    for(i = 1; i <= leaves_code; i++)              //初始化叶子结点
    {
        huffmancode[i].weight *= 100;
        huffmancode[i].parent = 0;
        huffmancode[i].lchild = 0;
        huffmancode[i].rchild = 0;
    }

    for(i = leaves_code+1; i <= code_count; i++)   //初始化后续结点
    {
        huffmancode[i].weight = 0;
        huffmancode[i].data = '0';
        huffmancode[i].parent = 0;
        huffmancode[i].lchild = 0;
        huffmancode[i].rchild = 0;
    }

    for(i = 1; i <= leaves_code; i++)                                                         //将结点按升序排序
    {
        for(j = 1; j < leaves_code; j++)
        {
            if(huffmancode[j].weight > huffmancode[j+1].weight)
            {
                temp = huffmancode[j];
                huffmancode[j] = huffmancode[j+1];
                huffmancode[j+1] = temp;
            }
        }
    }

    for(i = leaves_code+1; i <= code_count; i++)   //构造后续结点
    {
        sele_ct(huffmancode, i-1, &s1, &s2);
        huffmancode[i].weight = huffmancode[s1].weight+huffmancode[s2].weight;
        loop = huffmancode[i].weight;
        huffmancode[i].lchild = s1;
        huffmancode[i].rchild = s2;
        
        for(int k = 1; k <= i; k++)                                                         //将结点按升序排序
        {
            for(j = 1; j < i; j++)
            {
                if(huffmancode[j].weight > huffmancode[j+1].weight)
                {
                    temp = huffmancode[j];
                    huffmancode[j] = huffmancode[j+1];
                    huffmancode[j+1] = temp;
                }
            }
        }

        for(j = 1; j <= i; j++)
        {
            if(huffmancode[j].weight == loop && huffmancode[j].data == '0')
                break;
        }
        huffmancode[s1].parent = j;
        huffmancode[s2].parent = j;
    }
}

void Print_tree(HuffmanCode huffman[], HuffmanCode huffmancode, int h)      //打印哈夫曼树
{
    if(huffmancode.lchild == 0 && huffmancode.rchild == 0)                  //打印叶子结点
    {
        for(int i = 0; i < h; i++)
        {
            printf(" ");
        }
        printf("%c\n", huffmancode.data);

        return ;
    }

    Print_tree(huffman, huffman[huffmancode.rchild], h+3);

    for(int i = 0; i < h; i++)                                              //打印自制结点
    {
        printf(" ");
    }
    printf("%.0f\n", huffmancode.weight);

    Print_tree(huffman, huffman[huffmancode.lchild], h+3);
}

void Print_code(HuffmanCode huffman[], char *huffcode[], int n)             //打印每个叶子结点的编码
{
    char *cd;
    int start;
    int i, c, p;

    cd = (char *)malloc(n*sizeof(char));             //临时编码数组
    cd[n-1] = '\0';

    for(i = 1; i <= n; i++)
    {
        start = n-1;
        c = i;                                     //当前结点
        p = huffman[i].parent;                     //双亲结点

        while(p != 0)
        {
            --start;
            if(huffman[p].lchild == c)
            {
                cd[start] = '0';
            }
            if(huffman[p].rchild == c)
            {
                cd[start] = '1';
            }

            c = p;
            p = huffman[p].parent;
        }
        huffcode[i] = (char *)malloc(sizeof(char)*(n-start));  //每一个叶子结点的编码
        strcpy(huffcode[i], &cd[start]);
    }
    free(cd);

    for(i = 1; i <= n; i++)
    {
        if(huffman[i].lchild == 0 && huffman[i].rchild == 0)
        {
            printf("%c: ", huffman[i].data);
            printf("%s\n", huffcode[i]);
        }
    }
}

void print(char *huffcode[], HuffmanCode huffmancode[], int code_count)            //打印哈夫曼编码
{
    int i;
    char code[N];

    memset(code, 0, N);                                                            //初始化数组
    for(i = 1; i <= code_count; i++)
    {
        if(huffmancode[i].lchild == 0 && huffmancode[i].rchild == 0)
        {
            strcat(code, huffcode[i]);
        }
    }

    printf("%s\n", code);
}

int main()
{
    int leaves_code;
    int code_count;
    int i;
    char *huffcode[N];                             //用一个指针数组存放每个结点的编码
    HuffmanCode huffmancode[N];

    scanf("%d", &leaves_code);                     //输入叶子结点个数
    for(i = 1; i <= leaves_code; i++)
    {
        while(getchar() != '\n')
            continue;
        scanf("%c%f", &huffmancode[i].data, &huffmancode[i].weight);
    }

    code_count = 2*leaves_code -1;                 //哈夫曼树的结点数

    CtrHuffmantree(huffmancode, leaves_code, code_count);        //哈夫曼树的构造

    Print_tree(huffmancode, huffmancode[code_count], 1);         //打印哈夫曼树

    Print_code(huffmancode,  huffcode, code_count);              //打印每个叶子结点的编码

    print(huffcode, huffmancode, code_count);                    //打印编码
}
