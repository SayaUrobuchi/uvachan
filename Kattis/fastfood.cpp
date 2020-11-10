#include <iostream>

int nn[64], ary[64][64], val[64], stk[64];

int main()
{
	int count, n, m, i, j, best;
	long long ans;
	scanf("%d", &count);
	while (count--)
	{
		scanf("%d%d", &n, &m);
		for (i=0; i<n; i++)
		{
			scanf("%d", &nn[i]);
			for (j=0; j<nn[i]; j++)
			{
				scanf("%d", &ary[i][j]);
			}
			scanf("%d", &val[i]);
		}
		for (i=1; i<=m; i++)
		{
			scanf("%d", &stk[i]);
		}
		for (i=0, ans=0; i<n; i++)
		{
			for (j=0, best=2147483647; j<nn[i]; j++)
			{
				if (stk[ary[i][j]] < best)
				{
					best = stk[ary[i][j]];
				}
			}
			ans += (long long)best * val[i];
		}
		printf("%lld\n", ans);
	}
	return 0;
}
