#include <stdio.h>
#include <string.h>

int map[20][20], deg[20], n, m, d;
char used[20][1048576], dp[20][1048576];

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
		return dp[now][state]=1;
	}
	for(i=0; i<deg[now]; i++)
	{
		if(state & (1<<map[now][i]))
		{
			if(recursion(map[now][i], state-(1<<map[now][i]), num-1))
			{
				return dp[now][state]=1;
			}
		}
	}
	return dp[now][state]=0;
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
		for(k=0; k<n; k++)
		{
			for(i=0; i<n; i++)
			{
				for(j=0; j<n; j++)
				{
					map[i][j] = min(map[i][j], map[i][k]+map[k][j]);
				}
			}
		}
		for(i=0; i<n; i++)
		{
			deg[i] = 0;
			for(j=0; j<n; j++)
			{
				if(map[i][j] <= d)
				{
					map[i][deg[i]++] = j;
				}
			}
		}
		memset(used, 0, sizeof(used));
		for(i=0; i<n; i++)
		{
			if(recursion(i, (1<<n)-1, n))
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
