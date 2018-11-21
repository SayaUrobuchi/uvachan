#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int c[30], a[200000][30], id[200000], m, ss;

int comp(const void *p, const void *q)
{
	return memcmp(a[*(int*)p], a[*(int*)q], ss);
}

int main()
{
	int n, i, j, k, h, t, ms, ml, ans;
	while(scanf("%d%d", &n, &m) == 2)
	{
		ss = sizeof(int) * m;
		memset(c, 0, sizeof(c));
		for(i=0, h=0, ans=0; i<n; i++)
		{
			scanf("%d", &t);
			for(j=0; j<m; j++)
			{
				if(t & (1<<j))
				{
					h += (c[j]++ == 0);
					if(h == m)
					{
						for(k=0; k<m; k++)
						{
							c[k]--;
							h -= !c[k];
						}
					}
				}
			}
			if(h == 0)
			{
				ans = i+1;
			}
			memcpy(a[i], c, sizeof(c));
			id[i] = i;
		}
		qsort(id, n, sizeof(int), comp);
		for(i=0; i<n; i=j)
		{
			for(j=i+1, ms=ml=id[i]; j<n; j++)
			{
				if(memcmp(a[id[j]], a[id[i]], ss) == 0)
				{
					if(id[j] < ms)
					{
						ms = id[j];
					}
					if(id[j] > ml)
					{
						ml = id[j];
					}
				}
				else
				{
					break;
				}
			}
			if(ml-ms > ans)
			{
				ans = ml-ms;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
