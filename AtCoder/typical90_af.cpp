#include <iostream>
using namespace std;

int n, ans;
int used[16], valid[16], ary[16][16];

void dfs(int depth, int ok, int tim)
{
	int i;
	if (ans != -1 && tim >= ans)
	{
		return;
	}
	if (depth == n)
	{
		ans = tim;
		return;
	}
	for (i=0; i<n; i++)
	{
		if (!used[i] && (ok & (1<<i)))
		{
			used[i] = true;
			dfs(depth+1, valid[i], tim+ary[i][depth]);
			used[i] = false;
		}
	}
}

int main()
{
	int m, i, j, t, u;
	while (scanf("%d", &n) == 1)
	{
		for (i=0; i<n; i++)
		{
			for (j=0; j<n; j++)
			{
				scanf("%d", &ary[i][j]);
			}
			valid[i] = (1<<n)-1;
		}
		scanf("%d", &m);
		for (i=0; i<m; i++)
		{
			scanf("%d%d", &t, &u);
			--t, --u;
			valid[t] &= ~(1<<u);
			valid[u] &= ~(1<<t);
		}
		ans = -1;
		dfs(0, (1<<n)-1, 0);
		printf("%d\n", ans);
	}
	return 0;
}
