#include <stdio.h>
#include <string.h>

int dp[1001][100];
int length[1001];

int main()
{
	int n, i, j, len;
	dp[1][0] = 2;
	length[1] = 1;
	dp[2][0] = 5;
	length[2] = 1;
	dp[3][0] = 13;
	length[3] = 1;
	for(i=4; i<1001; i++)
	{
		for(j=0, len=length[i-1]; j<len; j++)
		{
			dp[i][j] += dp[i-1][j] + dp[i-1][j] + dp[i-2][j] + dp[i-3][j];
			if(dp[i][j] >= 100000000)
			{
				dp[i][j+1] += dp[i][j]/100000000;
				dp[i][j] %= 100000000;
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
		printf("%d", dp[n][length[n]-1]);
		for(i=length[n] - 2; i>-1; i--)
		{
			printf("%08d", dp[n][i]);
		}
		printf("\n");
	}
	return 0;
}
