/*************************************************************************
	> File Name: 哈希表.c
	> Author: HowYiAlaways
	> Mail: championhengyi@gmail.com
	> Created Time: 2017年06月01日 星期四 21时38分32秒
 ************************************************************************/

#include<stdio.h>

#define DEL -1
//哈希表的数据结构
#define HASHSIZE 11

typedef struct{
    int key;                         //关键字
}Datatype;

typedef struct{
    Datatype data;
    int times;                       //比较次数
}Hashtable[HASHSIZE];

//创建哈希函数（除留余数法）
int Hashfunc(int key)
{
    return key % HASHSIZE;
}

//处理冲突（线性探测再散列）
int Collision(int di)
{
    return (di+1) % HASHSIZE;
}

//哈希表的插入
int HashInsert(Hashtable ht, Datatype x)
{
    int address;

    //计算散列地址
    address = Hashfunc(x.key);

    //如果散列地址中已经有数值则进行冲突处理
    while(ht[address].data.key != NULL)
    {
        ht[address].times++;
        //冲突处理
        address = Collision(x.key);
    }

    //此散列地址没有数值，将数值放入此地址
    if(address >= 0)
    {
        ht[address].data = x;
        ht[address].times = 1;
    }

    return 1;
}

//哈希表的创建
void Createht(Hashtable ht, Datatype L[], int n)
{
    int i;

    //初始化哈希表（关键字和比较次数）
    for(i = 0; i < HASHSIZE; i++)
    {
        ht[i].data.key = NULL;
        ht[i].times = 0;
    }

    for(i = 0; i < n; i++)
    {
        HashInsert(ht, L[i]);
    }
}

//哈希表的查找
int HashSearch(Hashtable ht, Datatype x)
{
    int address;

    address = Hashfunc(x.key);

    while(ht[address].data.key != NULL && ht[address].data.key != x.key)
    {
        //处理冲突
        address = Collision(address);
    }

    if(ht[address].data.key == x.key)
    {
        //查找成功
        return address;
    }
    else
    {
        return -1;
    }
}

//哈希表的删除
int HashDel(Hashtable ht, Datatype x)
{
    int address;

    address = Hashfunc(x.key);

    //检查此散列地址中的数值是否已经删除
    while(ht[address].data.key != NULL && ht[address].data.key == DEL)
    {
        address = Collision(x.key);
    }

    if(address >= 0 && ht[address].data.key == DEL)
    {
        //设置删除标志
        ht[address].data.key = DEL;

        return 1;
    }
    else
    {
        //没有找到要删除的数值，删除失败，返回0
        return 0;               
    }
}
