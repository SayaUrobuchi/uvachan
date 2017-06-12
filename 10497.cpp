#include <stdio.h>
#include <string.h>

int dp[801][2000], length[801];

int main()
{
	int n, i, j, len;
	memset(dp, 0, sizeof(dp));
	dp[1][0] = 0;
	length[1] = 1;
	for(i=2; i<801; i++)
	{
		for(j=0, len=length[i-1]; j<len; j++)
		{
			dp[i][j] = dp[i-1][j] * i;
		}
		for(j=0; j<len; j++)
		{
			if(dp[i][j] > 9)
			{
				dp[i][j+1] += dp[i][j] / 10;
				dp[i][j] %= 10;
			}
		}
		if(dp[i][j])
		{
			while(dp[i][j++] > 9)
			{
				dp[i][j] += dp[i][j-1] / 10;
				dp[i][j-1] %= 10;
			}
		}
		len = j - 1;
		if(i % 2)
		{
            dp[i][0]--;
			for(j=0; j<len; j++)
			{
				if(dp[i][j] == -1)
				{
					dp[i][j] += 10;
					dp[i][j-1]--;
				}
				else
				{
					break;
				}
			}
			if(!dp[i][len++])
			{
				len--;
			}
		}
		else
		{
			dp[i][0]++;
			for(j=0; j<len; j++)
			{
				if(dp[i][j] > 9)
				{
					dp[i][j] -= 10;
					dp[i][j+1]++;
				}
				else
				{
					break;
				}
			}
			if(dp[i][len++] > 9)
			{
				dp[i][len-1] -= 10;
				dp[i][len++] = 1;
			}
		}
		length[i] = len;
	}
	while(scanf("%d", &n) == 1)
	{
		if(n == -1)
		{
			break;
		}
		for(i=length[n] - 1; i>-1; i--)
		{
			printf("%d", dp[n][i]);
		}
		printf("\n");
	}
	return 0;
}
