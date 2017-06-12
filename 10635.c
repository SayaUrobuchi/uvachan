#include <stdio.h>

int tbl[62501], dp[62500];

int main()
{
	int cas, count, n, m, i, j, in;
	cas = 0;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d%d%d", &in, &n, &m);
		for(i=0, n++, m++; i<n; i++)
		{
			scanf("%d", &in);
			tbl[in] = i;
		}
		for(i=0, n=0; i<m; i++)
		{
			scanf("%d", &in);
			for(j=n-1; j>-1; j--)
			{
				if(tbl[in] > tbl[dp[j]])
				{
					break;
				}
			}
			dp[++j] = in;
			n += (j == n);
		}
		printf("Case %d: %d\n", ++cas, n);
	}
	return 0;
}
