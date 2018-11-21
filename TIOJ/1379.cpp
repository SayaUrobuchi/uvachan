#include <stdio.h>
#include <string.h>

int map[20][20], n, m, d;
char used[20][1048576];
short dp[20][1048576];

int min(int p, int q)
{
	return p < q ? p : q;
}

int recursion(int now, int state, int num)
{
	int i;
	if(used[now][state])
	{
		return dp[now][state];
	}
	used[now][state] = 1;
	if(num == 1)
	{
		return dp[now][state]=0;
	}
	dp[now][state] = 10001;
	for(i=0; i<n; i++)
	{
		if(map[now][i] <= d && (state & (1<<i)))
		{
			if(recursion(i, state-(1<<i), num-1) + map[now][i] < dp[now][state])
			{
				dp[now][state] = dp[i][state-(1<<i)] + map[now][i];
			}
		}
	}
	if(dp[now][state] > 10001)
	{
		dp[now][state] = 10001;
	}
	return dp[now][state];
}

int main()
{
	int i, j, k;
	while(scanf("%d%d%d", &n, &m, &d) == 3)
	{
		memset(map, 1, sizeof(map));
		while(m--)
		{
			scanf("%d%d%d", &i, &j, &k);
			map[i][j] = map[j][i] = k;
		}
		memset(used, 0, sizeof(used));
		for(i=0; i<n; i++)
		{
			if(recursion(i, (1<<n)-1-(1<<i), n) <= d)
			{
				break;
			}
		}
		if(i < n)
		{
			printf("OK\n");
		}
		else
		{
			printf("...\n");
		}
	}
	return 0;
}
