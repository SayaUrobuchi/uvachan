#include <stdio.h>

int dp[1050][1050];
char s1[1020], s2[1020];

int min(int p, int q)
{
	return p<q ? p : q;
}

int main()
{
	int i, j;
	for(i=0; i<1050; i++)
	{
		dp[i][0] = dp[0][i] = i;
	}
	while(gets(s1))
	{
		gets(s2);
		for(i=0; s1[i]; i++)
		{
			for(j=0; s2[j]; j++)
			{
				if(s1[i] == s2[j])
				{
					dp[i+1][j+1] = dp[i][j];
				}
				else
				{
					dp[i+1][j+1] = min(dp[i][j], min(dp[i][j+1], dp[i+1][j])) + 1;
				}
			}
		}
		if(i == 0)
		{
			for(j=0; s2[j]; j++);
		}
		printf("%d\n", dp[i][j]);
	}
	return 0;
}
