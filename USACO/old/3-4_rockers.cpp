/*
	ID: sa072682
	LANG: C
	TASK: rockers
*/
#include <stdio.h>

int ary[21], n, t, m, ans;

void dfs(int now, int cd, int time, int num)
{
	if(now == n)
	{
		if(num > ans)
		{
			ans = num;
		}
		return;
	}
	dfs(now+1, cd, time, num);
	if(t - time >= ary[now])
	{
		dfs(now+1, cd, time+ary[now], num+1);
	}
	else
	{
		if(cd < m && ary[now] <= t)
		{
			dfs(now+1, cd+1, ary[now], num+1);
		}
		else
		{
			if(num > ans)
			{
				ans = num;
			}
		}
	}
}

int main()
{
	int i;
	freopen("rockers.in", "r", stdin);
	freopen("rockers.out", "w", stdout);
	scanf("%d%d%d", &n, &t, &m);
	for(i=0; i<n; i++)
	{
		scanf("%d", &ary[i]);
	}
	dfs(0, 1, 0, 0);
	printf("%d\n", ans);
	scanf(" ");
	return 0;
}
