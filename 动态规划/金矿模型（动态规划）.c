#include <stdio.h>
#define max_n 100 //程序规定最大的金矿数 
#define max_people 10000 //程序规定的最大挖矿人数 
int n;//金矿数（临时变量） 
int peopletotal;//人数 （临时变量）
int peopleneed[max_n];//挖第i座矿需要的人数  
int gold[max_n];//第i座矿能挖出的金子数 
int maxgold[max_people][max_n];//保存i个人挖前j个矿所得到的最大金子数，-1表示未知 (备忘录)
void init(int maxgold[][max_n])
{
	int i,j;
	for(i=0;i<max_people;i++)
	{
		for(j=0;j<max_n;j++)
		{
			maxgold[i][j]=-1;
		}
	}
}
int max(int x,int y)
{
	return (x>y?x:y);
 } 
int getmaxgold(int people,int minenum)
{
	int retmaxgold;//返回每个金矿能挖到的最大金子数 
	if(maxgold[people][minenum]!=-1)//做备忘录，备忘录存放解，-1为未知 
	{
		retmaxgold=maxgold[people][minenum];//直接从以前计算过的答案里寻找答案 
	}
	else if(minenum==0)
	{
		if(people>=peopleneed[minenum])
		{
			retmaxgold=gold[minenum];
		}
		else
			retmaxgold=0;
	}
	else if(people>=peopleneed[minenum])
	{
		retmaxgold=max(getmaxgold(people-peopleneed[minenum],minenum-1)+gold[minenum],
		getmaxgold(people,minenum-1)); 
	}
	else
		getmaxgold(people,minenum-1);
	maxgold[people][minenum]=retmaxgold;//做备忘录 
	return retmaxgold;
}
int main()
{
	int max,i;
	scanf("%d %d",&peopletotal,&n);//读入挖矿人数和矿数 
	init(maxgold);//对备忘录进行初始化 
	for(i=0;i<n;i++)
	{
		scanf("%d %d",&peopleneed[i],&gold[i]);
	} 
	max=getmaxgold(peopletotal,n-1);//每座矿能得到的最大金子数 （动态规划开始，转移方程式开始） 
	printf("%d",max);
	return 0;
 }
