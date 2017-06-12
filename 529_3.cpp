#include <stdio.h>
#include <string.h>
#include <math.h>

int n, lim;
int list[100], dp[30];

int dfs(int depth)
{
	int i, j, temp;
	if(list[depth-1] == n)
	{
		return 1;
	}
	if(depth == lim || list[depth-1] * dp[lim-depth] < n)
	{
		return 0;
	}
	for(j=depth-1; j>-1; j--)
	{
		if(list[depth-1] + list[j] <= n)
		{
			list[depth] = list[depth-1] + list[j];
			if(dfs(depth+1))
			{
				return 1;
			}
		}
	}
	return 0;
}

int main()
{
	int i;
	dp[0] = 1;
	for(i=1; i<30; i++)
	{
		dp[i] = dp[i-1] + dp[i-1];
	}
	while(scanf("%d", &n) == 1)
	{
		if(!n)
		{
			break;
		}
		for(i=1, lim=1; i<n; i+=i, lim++);
		list[0] = 1;
		for(; ; lim++)
		{
			/*printf("%d\n", lim);*/
			if(dfs(1))
			{
				break;
			}
		}
		printf("1");
		for(i=1; i<lim; i++)
		{
			printf(" %d", list[i]);
		}
		printf("\n");
	}
	return 0;
}
