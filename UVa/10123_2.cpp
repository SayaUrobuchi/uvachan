#include <stdio.h>

const int BIT = 1048576;
const int N = 24;

int n, cnt;
int pos[N], w[N];
int used[BIT], res[N];

int dfs(int depth, int left, int right, int stat)
{
	int i, t, nxt, nl, nr;
	if (used[stat] == cnt)
	{
		return 0;
	}
	used[stat] = cnt;
	if (depth == n)
	{
		for (i=0; i<n; i++)
		{
			printf("%d %d\n", pos[res[i]]>>1, w[res[i]]);
		}
		return 1;
	}
	for (i=0; i<n; i++)
	{
		if (stat & (1 << i))
		{
			nxt = stat - (1 << i);
			if (used[nxt] != cnt)
			{
				nl = left - (pos[i] + 3) * w[i];
				nr = right - (pos[i] - 3) * w[i];
				if (nl >= 0 && nr <= 0)
				{
					res[depth] = i;
					t = dfs(depth+1, nl, nr, nxt);
					if (t)
					{
						return t;
					}
				}
			}
		}
	}
	return 0;
}

int main()
{
	int len, wei, left, right, i;
	int cas;
	cnt = 0;
	cas = 0;
	while (scanf("%d%d%d", &len, &wei, &n) == 3)
	{
		if (len == 0 && wei == 0 && n == 0)
		{
			break;
		}
		left = 3 * wei;
		right = -3 * wei;
		for (i=0; i<n; i++)
		{
			scanf("%d%d", &pos[i], &w[i]);
			pos[i] <<= 1;
			left += (pos[i] + 3) * w[i];
			right += (pos[i] - 3) * w[i];
		}
		printf("Case %d:\n", ++cas);
		if (left < 0 || right > 0)
		{
			puts("Impossible");
			continue;
		}
		++cnt;
		if (!dfs(0, left, right, (1<<n)-1))
		{
			puts("Impossible");
		}
	}
	return 0;
}
