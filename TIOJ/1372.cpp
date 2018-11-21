#include <stdio.h>

int ans, n, m;
long long next[55], bit[55], final;

void dfs(int now, int nod, long long state)
{
	if(nod >= ans)
	{
		return;
	}
	if(state == final)
	{
		ans = nod;
		return;
	}
	if(now == m)
	{
		return;
	}
	if((state | next[now]) != final)
	{
		return;
	}
	if((state | bit[now]) != state)
	{
		dfs(now+1, nod+1, state|bit[now]);
	}
	dfs(now+1, nod, state);
}

int main()
{
	int i, p, q;
	while(scanf("%d%d", &n, &m) == 2)
	{
		for(i=0; i<m; i++)
		{
			scanf("%d%d", &p, &q);
			bit[i] = (1ll<<p) + (1ll<<q);
		}
		next[m-1] = bit[m-1];
		for(i=m-2; i>=0; i--)
		{
			next[i] = (next[i+1] | bit[i]);
		}
		if(next[0] != (final=(1ll<<n)-1))
		{
			printf("-1\n");
			continue;
		}
		ans = 2147483647;
		dfs(0, 0, 0);
		printf("%d\n", ans);
	}
	return 0;
}
