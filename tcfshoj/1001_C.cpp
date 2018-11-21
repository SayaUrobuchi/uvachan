#include <stdio.h>

int ary[2048], dp[2048][32];

int main()
{
	int count, n, k, i, j, kk, sum, t, tt, mx;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d%d", &n, &kk);
		for(i=1, sum=0; i<=n; i++)
		{
			scanf("%d", &ary[i]);
			sum += ary[i];
			dp[i][1] = sum;
			for(j=2; j<=kk; j++)
			{
				for(k=i, t=0, mx=-2147483647; k>=j; k--)
				{
					t += ary[k];
					if(t < dp[k-1][j-1])
					{
						tt = t;
					}
					else
					{
						tt = dp[k-1][j-1];
					}
					if(tt > mx)
					{
						mx = tt;
					}
				}
				dp[i][j] = mx;
			}
		}
		printf("%d\n", dp[n][kk]);
	}
	return 0;
}
