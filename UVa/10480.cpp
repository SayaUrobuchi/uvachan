#include <stdio.h>
#include <string.h>

#define START 1
#define END 2
#define INF 2147483647
#define N 64

int map[N][N];
int used[N], qq[N], qc[N], qf[N];

int main()
{
	int n, m, i, j, k, p, q, r, done, cnt, now;
	cnt = 0;
	while (scanf("%d%d", &n, &m) == 2)
	{
		if (!n && !m)
		{
			break;
		}
		memset(map, 0, sizeof(map));
		for (i=0; i<m; i++)
		{
			scanf("%d%d%d", &p, &q, &r);
			map[p][q] = map[q][p] = r;
		}
		done = 0;
		while (!done)
		{
			qq[0] = START;
			qc[0] = INF;
			++cnt;
			for (i=0, j=1; i<j; i++)
			{
				now = qq[i];
				if (now == END)
				{
					break;
				}
				for (k=1; k<=n; k++)
				{
					if (map[now][k] > 0 && used[k] != cnt)
					{
						used[k] = cnt;
						qq[j] = k;
						qc[j] = (map[now][k]<qc[i] ? map[now][k] : qc[i]);
						qf[j] = i;
						j++;
					}
				}
			}
			if (i >= j)
			{
				done = 1;
			}
			else
			{
				k = i;
				for (j=qf[i]; i; i=j, j=qf[i])
				{
					map[qq[i]][qq[j]] += qc[k];
					map[qq[j]][qq[i]] -= qc[k];
				}
			}
		}
		qq[0] = START;
		++cnt;
		used[START] = cnt;
		for (i=0, j=1; i<j; i++)
		{
			now = qq[i];
			for (k=1; k<=n; k++)
			{
				if (used[k] != cnt && map[now][k])
				{
					used[k] = cnt;
					qq[j] = k;
					j++;
				}
			}
		}
		for (i=1; i<=n; i++)
		{
			if (used[i] == cnt)
			{
				for (j=1; j<=n; j++)
				{
					if (!map[i][j] && map[j][i] && used[j] != cnt)
					{
						printf("%d %d\n", i, j);
					}
				}
			}
		}
		puts("");
	}
	return 0;
}
