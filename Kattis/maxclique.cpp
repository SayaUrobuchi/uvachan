#include <iostream>
using namespace std;

int best, n, m;
unsigned long long conn[64];

void dfs(int st, int cnt, unsigned long long stat)
{
	int i, guess;
	best = max(best, cnt);
	for (i=st, guess=0; i<n; i++)
	{
		if ((conn[i] & stat) == stat)
		{
			++guess;
		}
	}
	if (cnt + guess <= best)
	{
		return;
	}
	for (i=st; i<n; i++)
	{
		if ((conn[i] & stat) == stat)
		{
			dfs(i+1, cnt+1, stat|(1LLU<<i));
		}
	}
}

int main()
{
	int i, a, b;
	scanf("%d%d", &n, &m);
	for (i=0; i<m; i++)
	{
		scanf("%d%d", &a, &b);
		conn[a] |= (1LLU<<b);
		conn[b] |= (1LLU<<a);
	}
	best = 1;
	for (i=0; i<n; i++)
	{
		dfs(i+1, 1, (1LLU<<i));
	}
	printf("%d\n", best);
	return 0;
}