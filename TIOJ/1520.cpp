#include <stdio.h>
#include <string.h>

int dp[150000][3];
char str[150000];

int main()
{
	int count, n, i, j, k, temp;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d", &n);
		scanf("%s", str+1);
		memset(dp, 0, sizeof(dp));
		temp = str[0] - 97;
		for(i=0; i<3; i++)
		{
			dp[0][i] = 1;
		}
		for(i=2; i<=n; i++)
		{
			for(j=0; j<3; j++)
			{
				if(j != str[i-1] - 97)
				{
					for(k=0; k<3; k++)
					{
						dp[i][j] |= dp[i-2][k];
					}
					dp[i][j] |= dp[i-1][3-(str[i-1]-97+j)];
				}
			}
		}
		printf(dp[n][str[n]-97]?"YES\n":"NO\n");
	}
	return 0;
}
