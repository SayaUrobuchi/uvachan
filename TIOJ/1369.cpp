#include <stdio.h>

int ans[50005], ary[50005], id[50005], c;

void dfs(int now)
{
	int i;
	ans[now] = c++;
	for(i=id[now]; i<id[now+1]; i++)
	{
		dfs(ary[i]);
	}
}

int main()
{
	int n, m, i, j, k;
	while(scanf("%d", &n) == 1)
	{
		for(i=1, j=0; i<=n; i++)
		{
			scanf("%d", &m);
			id[i] = j;
			for(; m; m--, j++)
			{
				scanf("%d", &ary[j]);
			}
		}
		id[i] = j;
		c = 1;
		dfs(1);
		for(i=1; i<=n; i++)
		{
			printf("%d\n", ans[i]);
		}
	}
	return 0;
}
