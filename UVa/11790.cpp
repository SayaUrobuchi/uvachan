#include <stdio.h>

#define N 2048

int h[N], dp0[N], dp1[N];

int main()
{
	int count, cas, n, i, j, p, q, w;
	cas = 0;
	scanf("%d", &count);
	while (count--)
	{
		scanf("%d", &n);
		for (i=0; i<n; i++)
		{
			scanf("%d", &h[i]);
		}
		p = 0;
		q = 0;
		for (i=0; i<n; i++)
		{
			scanf("%d", &w);
			dp0[i] = w;
			dp1[i] = w;
			for (j=0; j<i; j++)
			{
				if (h[j] < h[i])
				{
					if (dp0[j] + w > dp0[i])
					{
						dp0[i] = dp0[j] + w;
					}
				}
				else if (h[j] > h[i])
				{
					if (dp1[j] + w > dp1[i])
					{
						dp1[i] = dp1[j] + w;
					}
				}
			}
			if (dp0[i] > p)
			{
				p = dp0[i];
			}
			if (dp1[i] > q)
			{
				q = dp1[i];
			}
		}
		if (p >= q)
		{
			printf("Case %d. Increasing (%d). Decreasing (%d).\n", ++cas, p, q);
		}
		else
		{
			printf("Case %d. Decreasing (%d). Increasing (%d).\n", ++cas, q, p);
		}
	}
	return 0;
}
