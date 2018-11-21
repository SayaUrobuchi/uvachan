#include <stdio.h>

int dp[305][305][305][2];

int main()
{
	int count, n, m, k, w, h, cut, i, j, res, *p;
	for(w=1; w<=300; w++)
	{
		for(k=w; k<=300; k++)
		{
			for(h=1; h+h<=k; h++)
			{
				for(cut=0; cut<2; cut++)
				{
					p = &dp[h][w][k][cut];
					if(w < k)
					{
						*p = 0;
						continue;
					}
					if(k == 1)
					{
						*p = 1;
						continue;
					}
					if(cut)
					{
						for(i=1; i<w; i++)
						{
							for(j=1; j<k; j++)
							{
								*p = ((long long)dp[h][i][j][1] * dp[h][w-i][k-j][0] + *p) % 1000000007;
							}
						}
					}
					for(i=1; i<w; i++)
					{
						for(j=1; j+i+k-1<=w; j++)
						{
							*p = (*p+dp[h-1][w-j-i][k-1][0]) % 1000000007;
						}
					}
				}
			}
		}
	}
	printf("done!\n");
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d%d%d", &n, &m, &k);
		if(m > k/2)
		{
			m = k/2;
		}
		res = dp[n][m][k][1];
		for(i=1; i<=k; i++)
		{
			res = (long long)res*i % 1000000007;
		}
		printf("%d\n", res);
	}
	return 0;
}
