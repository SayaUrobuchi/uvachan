#include <stdio.h>
#include <string.h>

const int N = 8;
const int M = 20;

int n;
int used[N], path[N], tbl[N][M], val[N][M], tn[N];

int dfs(int depth)
{
	int res, i, j, k, c;
	if (depth == n)
	{
		return 1;
	}
	res = 0;
	for (i=0; i<n; i++)
	{
		if (used[i] < 0)
		{
			for (j=0; j<tn[i]; j++)
			{
				k = tbl[i][j];
				c = val[i][j];
				if (used[k] >= 0)
				{
					if (c > 0 && depth-used[k] > c)
					{
						break;
					}
					if (c < 0 && depth-used[k] < -c)
					{
						break;
					}
				}
			}
			if (j >= tn[i])
			{
				path[depth] = i;
				used[i] = depth;
				res += dfs(depth+1);
				used[i] = -1;
			}
		}
	}
	return res;
}

int main()
{
	int m, i, p, q, r;
	while (scanf("%d%d", &n, &m) == 2)
	{
		if (n == 0 && m == 0)
		{
			break;
		}
		memset(tn, 0, sizeof(tn));
		for (i=0; i<m; i++)
		{
			scanf("%d%d%d", &p, &q, &r);
			tbl[p][tn[p]] = q;
			val[p][tn[p]] = r;
			tn[p]++;
			tbl[q][tn[q]] = p;
			val[q][tn[q]] = r;
			tn[q]++;
		}
		memset(used, -1, sizeof(used));
		printf("%d\n", dfs(0));
	}
	return 0;
}
