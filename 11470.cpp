#include <stdio.h>

int map[12][12];

int main()
{
	int cas, n, i, j, p, q, sum;
	cas = 0;
	while(scanf("%d", &n) == 1)
	{
		if(n == 0)
		{
			break;
		}
		for(i=0; i<n; i++)
		{
			for(j=0; j<n; j++)
			{
				scanf("%d", &map[i][j]);
			}
		}
		printf("Case %d:", ++cas);
		for(p=0, q=n-1; p<=q; p++, q--)
		{
			for(i=p, sum=0; i<=q; i++)
			{
				sum += map[i][p] + (p+p==n-1?0:map[i][n-p-1]);
			}
			for(i=p+1; i<q; i++)
			{
				sum += map[p][i] + map[n-p-1][i];
			}
			printf(" %d", sum);
		}
		printf("\n");
	}
	return 0;
}
