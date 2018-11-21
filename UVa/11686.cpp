#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N 1048576

int qq[N], qn;
int deg[N], st[N], ed[N], idx[N], from[N];

int comp(const void *p, const void *q)
{
	return st[*(int*)p] > st[*(int*)q] ? 1 : -1;
}

int main()
{
	int n, m, i, j, now, nxt;
	while (scanf("%d%d", &n, &m) == 2)
	{
		if (!n && !m)
		{
			break;
		}
		memset(deg, 0, sizeof(deg));
		for (i=0; i<m; i++)
		{
			scanf("%d%d", &st[i], &ed[i]);
			idx[i] = i;
			deg[ed[i]]++;
		}
		qsort(idx, m, sizeof(idx[0]), comp);
		for (i=0; i<m; i++)
		{
			from[st[idx[i]]] = i;
		}
		qn = 0;
		for (i=1; i<=n; i++)
		{
			if (!deg[i])
			{
				qq[qn++] = i;
			}
		}
		for (i=0; i<qn; i++)
		{
			now = qq[i];
			if (from[now] < m)
			{
				for (j=from[now]; j>=0&&st[idx[j]]==now; j--)
				{
					nxt = ed[idx[j]];
					if (!--deg[nxt])
					{
						qq[qn++] = nxt;
					}
				}
			}
		}
		if (qn != n)
		{
			puts("IMPOSSIBLE");
		}
		else
		{
			for (i=0; i<qn; i++)
			{
				printf("%d\n", qq[i]);
			}
		}
	}
	return 0;
}
