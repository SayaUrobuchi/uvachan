#include<stdio.h>
#include<string.h>
int n,k,sav[501],tmp2[501];
int dfs(int i,int j)
{
	int w,x,min;
	if(i>j-1)
	{
		return 0;
	}
	for(w=i,min=0;w<j+1;w++)
	{
		min=dfs(i,w-1)+k+w+dfs(w+1,j);
		if(x<min||!min)
		{
			min=x;
		}
	}
	return min;
}
int main()
{
	int i,j,l,count,cas;
	scanf("%d",&count);
	for(cas=1,count++;cas<count;cas++)
	{
		scanf("%d%d",&n,&k);
		memset(sav,0,n*4+4);
		printf("Case %d: %d\n",cas,dfs(1,n));
	}
	return 0;
}