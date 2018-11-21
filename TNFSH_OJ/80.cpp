#include <stdio.h>

int ary[1024], dp[1024][1024];

int main()
{
	int n, i, j, k, p, q, sum;
	while (scanf("%d", &n) == 1)
	{
		for (i=0, sum=0; i<n; i++)
		{
			scanf("%d", &ary[i]);
			dp[i][j] = ((n&1)?ary[i]:0);
			sum += ary[i];
		}
		for (i=1; i<n; i++)
		{
			for (j=0, k=i+j; k<n; j++, k++)
			{
				if ((n&1) == (i&1))
				{
					p = dp[j+1][k];
					q = dp[j][k-1];
					dp[j][k] = (p>q ? q : p);
				}
				else
				{
					p = dp[j+1][k] + ary[j];
					q = dp[j][k-1] + ary[k];
					dp[j][k] = (p>q ? p : q);
				}
			}
		}
		printf("%d %d\n", dp[0][n-1], sum-dp[0][n-1]);
		break;
	}
	return 0;
}
