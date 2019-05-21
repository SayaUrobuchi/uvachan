#include <stdio.h>

const int ANY = 0;
const int MUST = 1;

int ucnt;
int cc[1024], conn[1024][1024];
int dp[1024][2], used[1024][2];

int calc(int par, int cur, int stat)
{
	int i, a, b, nxt, res;
	if (used[cur][stat] == ucnt)
	{
		return dp[cur][stat];
	}
	used[cur][stat] = ucnt;
	a = 0;
	b = 0;
	for (i=0; i<cc[cur]; i++)
	{
		nxt = conn[cur][i];
		if (nxt != par)
		{
			a += calc(cur, nxt, ANY);
			b += calc(cur, nxt, MUST);
		}
	}
	res = a + 1;
	if (stat == ANY && cc[cur] && res > b)
	{
		res = b;
	}
	return dp[cur][stat] = res;
}

int main()
{
	int n, i, j;
	while (scanf("%d", &n) == 1)
	{
		if (n == 0)
		{
			break;
		}
		++ucnt;
		for (i=1; i<=n; i++)
		{
			scanf("%d", &cc[i]);
			for (j=0; j<cc[i]; j++)
			{
				scanf("%d", &conn[i][j]);
			}
		}
		printf("%d\n", calc(0, 1, ANY));
	}
	return 0;
}
