#include <iostream>

int n, ans;
int ary[32];

void dfs(int depth, int stat)
{
	if (depth == n)
	{
		++ans;
		return;
	}
	dfs(depth+1, stat);
	if (stat & (1 << depth))
	{
		dfs(depth+1, stat&~ary[depth]);
	}
}

int main()
{
	int m, i, a, b;
	while (scanf("%d%d", &n, &m) == 2)
	{
		for (i=0; i<n; i++)
		{
			ary[i] = 0;
		}
		for (i=0; i<m; i++)
		{
			scanf("%d%d", &a, &b);
			--a, --b;
			ary[a] |= (1 << b);
			ary[b] |= (1 << a);
		}
		ans = 0;
		dfs(0, (1<<n)-1);
		printf("%d\n", ans);
	}
	return 0;
}
