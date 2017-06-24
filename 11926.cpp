#include <stdio.h>
#include <stdlib.h>

#define M 1000000

int st[256], ed[256], inv[256], idx[256];

int comp(const void *p, const void *q)
{
	return inv[*(int*)p] > inv[*(int*)q] ? 1 : -1;
}

int main()
{
	int n, m, i, j, k, p, q, r, a, over;
	while (scanf("%d%d", &n, &m) == 2)
	{
		if (!n && !m)
		{
			break;
		}
		over = 0;
		for (i=0; i<n; i++)
		{
			scanf("%d%d", &st[i], &ed[i]);
			inv[i] = 1048576;
			idx[i] = i;
		}
		m += n;
		for (; i<m; i++)
		{
			scanf("%d%d%d", &st[i], &ed[i], &inv[i]);
			if (inv[i]+st[i] < ed[i])
			{
				over = 1;
			}
			idx[i] = i;
		}
		if (!over)
		{
			qsort(idx, m, sizeof(int), comp);
			for (i=1; i<m; i++)
			{
				p = idx[i];
				for (j=0; j<i; j++)
				{
					q = idx[j];
					for (k=0; k+st[p]<=M; k+=inv[p])
					{
						r = k + st[p];
						/* inv[q]*a + ed[q] > r */
						if (ed[q] > r)
						{
							a = 0;
						}
						else
						{
							a = (r-ed[q])/inv[q] + 1;
						}
						if (inv[q]*a+st[q] <= M && inv[q]*a + ed[q] > k+st[p] && k+ed[p] > inv[q]*a + st[q])
						{
							break;
						}
					}
					if (k+st[p] <= M)
					{
						break;
					}
				}
				if (j < i)
				{
					break;
				}
			}
		}
		if (!over && i >= m)
		{
			puts("NO CONFLICT");
		}
		else
		{
			puts("CONFLICT");
		}
	}
	return 0;
}
