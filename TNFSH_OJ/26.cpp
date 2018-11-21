#include <stdio.h>

int dp[3005][3005];
char s[3005];

int main()
{
	int count, len, i, j, k;
	scanf("%d", &count);
	while (count--)
	{
		scanf("%s", &s);
		for (len=0; s[len]; len++)
		{
			dp[len][len] = 1;
		}
		for (k=1; k<len; k++)
		{
			for (i=0, j=i+k; j<len; j++, i++)
			{
				if (s[i] == s[j])
				{
					dp[i][j] = dp[i+1][j-1] + 2;
				}
				else
				{
					dp[i][j] = (dp[i+1][j] > dp[i][j-1] ? dp[i+1][j] : dp[i][j-1]);
				}
			}
		}
		printf("%d\n", dp[0][len-1]);
	}
	return 0;
}
