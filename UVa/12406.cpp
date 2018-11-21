#include <stdio.h>

int n, m;
long long m0, m1;

void dfs(int depth, long long now)
{
	if (depth == n)
	{
		if (!(now % (1<<m)))
		{
			if (now < m0)
			{
				m0 = now;
			}
			m1 = now;
		}
		return;
	}
	dfs(depth+1, now*10+1);
	dfs(depth+1, now*10+2);
}

int main()
{
	int cas, count;
	cas = 0;
	scanf("%d", &count);
	while (count--)
	{
		scanf("%d%d", &n, &m);
		m0 = (1LL<<62);
		m1 = -1;
		dfs(0, 0LL);
		printf("Case %d:", ++cas);
		if (m1 < 0)
		{
			puts(" impossible");
		}
		else
		{
			printf(" %lld", m0);
			if (m0 != m1)
			{
				printf(" %lld", m1);
			}
			puts("");
		}
	}
	return 0;
}
