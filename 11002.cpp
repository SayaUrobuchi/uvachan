#include <stdio.h>
#include <string.h>

char dp[31][6005], dp2[31][6005];

int main()
{
	int n, i, j, k, temp, type;
	while(scanf("%d", &n) == 1)
	{
		if(!n)
		{
			break;
		}
		memset(dp, 0, sizeof(dp));
		scanf("%d", &temp);
		dp[0][temp+3000] = 1;
		memset(dp2, 0, sizeof(dp2));
		for(i=1, type=0; i<n; i++)
		{
			for(j=0; j<=i; j++)
			{
				scanf("%d", &temp);
				if(type == 0)
				{
					for(k=50; k<=5950; k++)
					{
						if(j > 0)
						{
							dp2[j][k-temp] |= dp[j-1][k];
							dp2[j][k+temp] |= dp[j-1][k];
						}
						if(j < i)
						{
							dp2[j][k-temp] |= dp[j][k];
							dp2[j][k+temp] |= dp[j][k];
						}
					}
				}
				else
				{
					for(k=50; k<=5950; k++)
					{
						if(j > 0)
						{
							dp[j][k-temp] |= dp2[j-1][k];
							dp[j][k+temp] |= dp2[j-1][k];
						}
						if(j < i)
						{
							dp[j][k-temp] |= dp2[j][k];
							dp[j][k+temp] |= dp2[j][k];
						}
					}
				}
			}
			if(type == 0)
			{
				memset(dp, 0, sizeof(dp));
			}
			else
			{
				memset(dp2, 0, sizeof(dp2));
			}
			type = 1 - type;
		}
		for(i=n-1; i>0; i--)
		{
			for(j=0; j<i; j++)
			{
				scanf("%d", &temp);
				if(type == 0)
				{
					for(k=50; k<=5950; k++)
					{
						dp2[j][k-temp] |= (dp[j][k] | dp[j+1][k]);
						dp2[j][k+temp] |= (dp[j][k] | dp[j+1][k]);
					}
				}
				else
				{
					for(k=50; k<=5950; k++)
					{
						dp[j][k-temp] |= (dp2[j][k] | dp2[j+1][k]);
						dp[j][k+temp] |= (dp2[j][k] | dp2[j+1][k]);
					}
				}
			}
			if(type == 0)
			{
				memset(dp, 0, sizeof(dp));
			}
			else
			{
				memset(dp2, 0, sizeof(dp2));
			}
			type = 1 - type;
		}
		for(i=3000, j=3000; i>=0&&j<=6000; i--, j++)
		{
			if(type == 0)
			{
				if(dp[0][i] || dp[0][j])
				{
					break;
				}
			}
			else
			{
				if(dp2[0][i] || dp2[0][j])
				{
					break;
				}
			}
		}
		printf("%d\n", j-3000);
	}
	return 0;
}
