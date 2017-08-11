/*************************************************************************
	> File Name: creattree.c
	> Author: Paranoid
	> Mail: championhengyi@gmail.com
	> Created Time: 2016年10月30日 星期日 15时34分21秒
 ************************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define N 100

typedef struct Node{
    char data;
    struct Node *leftChild;
    struct Node *rightChild;
}node;

void printTree(node *root,int h)                    //逆中序按树状结构打印二叉树
{
	int i ;

    if(root == NULL)
    {
        return ;
    }

    printTree(root -> rightChild, h+1);

    for(i = 1; i <= h; i++)
    {
        printf("   ");
    }
    printf("%c\n",root -> data);

    printTree(root -> leftChild,h+1);
}

node *anotherCreatTree(node *root, char a[], char b[], int len)
{
    if(len <= 0)                                    //当左右子树的长度都为0时，函数返回
    {
        return root = NULL;
    }
    else
    {
        char *temp = NULL;
        int k = 0;

        root = (node *)malloc(sizeof(node));
        root -> data = *a;                          //根节点等于先序序列的第一个结点

        for(temp = b; *temp != *a; temp++)          //将左子树和右子树找到，并确定根结点在中序序列中的位置
        {
            k++;
        }

        root -> leftChild = anotherCreatTree(root -> leftChild, a+1, b, k);                       //递归可以确定左子树
        root -> rightChild = anotherCreatTree(root -> rightChild, a+1+k, temp+1, len-1-k);        //递归可以确定右子树

        return root;
    }
}

node *another_CreatTree(node *root, char a[], char b[], int len)
{
    if(len <= 0)                                    //当左右子树的长度都为0时，函数返回
    {
        return root = NULL;
    }
    else
    {
        char *temp = NULL;
        int k = 0;

        root = (node *)malloc(sizeof(node));
        root -> data = b[len-1];                    //由后序确定根节点

        for(temp = a; *temp != b[len-1]; temp++)    //找到左右子树的位置
        {
            k++;
        }

        root -> leftChild = another_CreatTree(root -> leftChild, a, b, k);
        root -> rightChild = another_CreatTree(root -> rightChild, temp+1, b+k, len-1-k);

        return root;
    }
}

int main()
{
    int number;
    char b[N];
    char c[N];
    node *anotherRoot = NULL;                       //初始化根节点

    scanf("%d", &number);
    scanf("%s",b);
    scanf("%s",c);

    if(number == 1)
    {
        printf("由先序和中序确定二叉树：\n");
        anotherRoot = anotherCreatTree(anotherRoot, b, c, strlen(b));
    }

    if(number == 2)
    {
        printf("由中序和后序确定二叉树：\n");
        anotherRoot = another_CreatTree(anotherRoot, b, c, strlen(b));
    }

    printTree(anotherRoot,1);

    return 0;
}
