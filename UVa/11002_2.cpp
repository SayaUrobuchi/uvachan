#include <stdio.h>
#include <string.h>

char dp[31][3055], dp2[31][3055];

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
					for(k=50; k<=3000; k++)
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
					for(k=50; k<=3000; k++)
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
					for(k=50; k<=3000; k++)
					{
						dp2[j][k-temp] |= (dp[j][k] | dp[j+1][k]);
						dp2[j][k+temp] |= (dp[j][k] | dp[j+1][k]);
					}
				}
				else
				{
					for(k=50; k<=3000; k++)
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
		for(i=3000; i>=0; i--)
		{
			if(type == 0)
			{
				if(dp[0][i])
				{
					break;
				}
			}
			else
			{
				if(dp2[0][i])
				{
					break;
				}
			}
		}
		printf("%d\n", 3000-i);
	}
	return 0;
}
