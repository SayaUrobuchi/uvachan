#include <iostream>

int n, ans;
int board[16];

void dfs(int depth, int a, int b, int c)
{
	int t, u;
	if (depth == n)
	{
		++ans;
		return;
	}
	t = (~(a|b|c) & board[depth]);
	while (t)
	{
		u = (t & -t);
		dfs(depth+1, a|u, (b|u)<<1, (c|u)>>1);
		t &= ~u;
	}
}

int main()
{
	int m, i, p, q;
	while (scanf("%d%d", &n, &m) == 2)
	{
		if (n == 0 && m == 0)
		{
			break;
		}
		for (i=0; i<n; i++)
		{
			board[i] = (1<<n) - 1;
		}
		for (i=0; i<m; i++)
		{
			scanf("%d%d", &p, &q);
			board[p] &= ~(1<<q);
		}
		ans = 0;
		dfs(0, 0, 0, 0);
		printf("%d\n", ans);
	}
	return 0;
}
