#include <stdio.h>
#include <stdlib.h>

int a[1024], b[1024], p[1024];

int comp(const void *p, const void *q)
{
	int pp = *(int*)p;
	int qq = *(int*)q;
	if (b[pp] != b[qq])
	{
		return b[qq] - b[pp];
	}
	return a[pp] - a[qq];
}

int main()
{
	int cas, n, i, t, res, las;
	cas = 0;
	while (scanf("%d", &n) == 1)
	{
		if (!n)
		{
			break;
		}
		for (i=0; i<n; i++)
		{
			scanf("%d%d", &a[i], &b[i]);
			p[i] = i;
		}
		qsort(p, n, sizeof(p[0]), comp);
		res = 0;
		las = 0;
		for (i=0; i<n; i++)
		{
			las += a[p[i]];
			t = las + b[p[i]];
			if (t > res)
			{
				res = t;
			}
		}
		printf("Case %d: %d\n", ++cas, res);
	}
	return 0;
}
