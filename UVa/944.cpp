#include <stdio.h>

int dp[100000];
int tbl[10];
char buf[10];

int trans(int now)
{
	int i, result;
	sprintf(buf, "%d", now);
	for(i=0, result=0; buf[i]; i++)
	{
		result += tbl[buf[i]-48];
	}
	return result;
}

int recursion(int now)
{
	int temp;
	if(dp[now] == 99999)
	{
		return 0;
	}
	else if(dp[now])
	{
		return dp[now];
	}
	if(now == 1)
	{
		return dp[1] = 1;
	}
	dp[now] = 99999;
	temp = recursion(trans(now));
	if(!temp)
	{
		return 0;
	}
	return dp[now]=temp+1;
}

int main()
{
	int cas, n, m, i, temp;
	cas = 0;
	for(i=1; i<10; i++)
	{
		tbl[i] = i * i;
	}
	while(scanf("%d%d", &n, &m) == 2)
	{
		if(cas)
		{
			printf("\n");
		}
		cas = 1;
		for(i=n; i<=m; i++)
		{
			temp = recursion(i);
			if(temp)
			{
				printf("%d %d\n", i, dp[i]);
			}
		}
	}
	return 0;
}
