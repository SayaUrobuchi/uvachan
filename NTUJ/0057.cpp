#include <stdio.h>

int dp[105][105];
char s1[105], s2[105];

int main()
{
	int count, i, j;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%s%s", s1+1, s2+1);
		for(i=1; s1[i]; i++)
		{
			for(j=1; s2[j]; j++)
			{
				if(s1[i] == s2[j])
				{
					dp[i][j] = dp[i-1][j-1] + 1;
				}
				else
				{
					dp[i][j] = dp[i-1][j] > dp[i][j-1] ? dp[i-1][j] : dp[i][j-1];
				}
			}
		}
		printf("%d\n", dp[i-1][j-1]);
	}
	return 0;
}
