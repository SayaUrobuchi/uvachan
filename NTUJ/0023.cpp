#include <stdio.h>

int dp[105], ary[105], tbl[10], n, ans;

void lis()
{
	int m, i, j;
	for(i=1, m=-1; i<=n; i++)
	{
		for(j=m; j>=0&&dp[j]>tbl[ary[i]]; j--);
		dp[++j] = tbl[ary[i]];
		if(j > m)
		{
			m = j;
		}
	}
	if(m > ans)
	{
		ans = m;
	}
}

void dfs(int depth)
{
	int i;
	if(depth > 5)
	{
		lis();
		return;
	}
	for(i=1; i<=5; i++)
	{
		if(tbl[i] == 0)
		{
			tbl[i] = depth;
			dfs(depth+1);
			tbl[i] = 0;
		}
	}
}

int main()
{
	int m, i;
	while(scanf("%d%d", &n, &m) == 2)
	{
		if(n == 0 && m == 0)
		{
			break;
		}
		for(i=1; i<=n; i++)
		{
			scanf("%d", &ary[i]);
		}
		ans = 0;
		dfs(1);
		printf("%d\n", n-ans-1);
	}
	return 0;
}
