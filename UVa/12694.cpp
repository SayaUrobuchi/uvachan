#include <stdio.h>

int c, ans;
int ary[32];

void dfs(int ss, int d, int mask)
{
	int i;
	if (d > ans)
	{
		ans = d;
	}
	for (i=ss; i<c; i++)
	{
		if (!(mask & ary[i]))
		{
			dfs(i+1, d+1, mask|ary[i]);
		}
	}
}

int main()
{
	int count, n, m, i, k;
	scanf("%d", &count);
	while (count--)
	{
		c = 0;
		while (1)
		{
			scanf("%d%d", &n, &m);
			if (!n && !m)
			{
				break;
			}
			k = 0;
			for (i=n; i<m; i++)
			{
				k |= (1<<i);
			}
			ary[c++] = k;
		}
		ans = 0;
		dfs(0, 0, 0);
		printf("%d\n", ans);
	}
	return 0;
}
