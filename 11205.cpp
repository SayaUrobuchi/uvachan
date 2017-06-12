#include <stdio.h>
#include <string.h>

int ary[100][15], dp[16], ans, n, m;
char check[15], temp[32768], list[15];

char comp(int length)
{
	int i, j, k;
	memset(temp, 0, dp[length]);
	for(i=0; i<m; i++)
	{
		for(j=0, k=0; j<length; j++)
		{
			if(ary[i][list[j]])
			{
				k += dp[j];
			}
		}
		if(temp[k])
		{
			return 0;
		}
		temp[k] = 1;
	}
	return 1;
}

void dfs(int length, int last)
{
	int i;
	if(length + 1 == ans)
	{
		return;
	}
	for(i=last; i<n; i++)
	{
		if(!check[i])
		{
			check[i] = 1;
			list[length] = i;
			if(comp(length+1))
			{
				ans = length + 1;
				check[i] = 0;
				return;
			}
			if(length + 2 < ans)
			{
            	dfs(length+1, i+1);
			}
			check[i] = 0;
		}
	}
}

int main()
{
	int count, i, j;
	dp[0] = 1;
	for(i=1; i<16; i++)
	{
		dp[i] = dp[i-1] * 2;
	}
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d%d", &n, &m);
		for(i=0; i<m; i++)
		{
			for(j=0; j<n; j++)
			{
				scanf("%d", &ary[i][j]);
			}
		}
		ans = n;
		memset(check, 0, sizeof(check));
		dfs(0, 0);
		printf("%d\n", ans);
	}
	return 0;
}
