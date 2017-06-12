#include <stdio.h>
#include <string.h>

char dp[1001][407];
int length[1001];

int main()
{
	int n, i, j, len;
	memset(dp, 0, sizeof(dp));
	dp[1][0] = 2;
	length[1] = 1;
	dp[2][0] = 5;
	length[2] = 1;
	dp[3][0] = 3;
	dp[3][1] = 1;
	length[3] = 2;
	for(i=4; i<1001; i++)
	{
		for(j=0, len=length[i-1]; j<len; j++)
		{
			dp[i][j] += dp[i-1][j] + dp[i-1][j] + dp[i-2][j] + dp[i-3][j];
			if(dp[i][j] > 9)
			{
				dp[i][j+1] = dp[i][j] / 10;
				dp[i][j] %= 10;
			}
		}
		if(dp[i][j])
		{
			j++;
		}
		length[i] = j;
	}
	while(scanf("%d", &n) == 1)
	{
		for(i=length[n] - 1; i>-1; i--)
		{
			printf("%d", dp[n][i]);
		}
		printf("\n");
	}
	return 0;
}
