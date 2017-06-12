#include <stdio.h>

int ary[602], value[602], dp[602][301];

int max(int p, int q)
{
	if(p > q)
	{
		return p;
	}
	return q;
}

int main()
{
	int n, k, i, j, p, q;
	while(scanf("%d%d", &n, &k) == 2)
	{
		for(i=1, n+=2, k++; i<n; i++)
		{
			scanf("%d", &ary[i]);
			value[i] = ary[i] + value[i-1];
			dp[i][0] = value[i];
			for(j=1; j<k; j++)
			{
				dp[i][j] = max(dp[i-1][j-1], value[i]-value[i-1]);
				for(p=i-2; p>0; p--)
				{
					if(value[i]-value[p] < dp[i][j])
					{
						if(max(dp[p][j-1], value[i]-value[p]) < dp[i][j])
						{
							dp[i][j] = max(dp[p][j-1], value[i]-value[p]);
						}
					}
					else
					{
						break;
					}
				}
			}
		}
		printf("%d\n", dp[n-1][k-1]);
	}
	return 0;
}
