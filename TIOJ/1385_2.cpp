#include <stdio.h>

int dp[1050][1050];
char s1[1020], s2[1020];

int max(int p, int q)
{
	return p>q ? p : q;
}

int main()
{
	int i, j;
	while(gets(s1))
	{
		gets(s2);
		for(i=0; s1[i]; i++)
		{
			for(j=0; s2[j]; j++)
			{
				if(s1[i] == s2[j])
				{
					dp[i+1][j+1] = dp[i][j] + 1;
				}
				else
				{
					dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j]);
				}
			}
		}
		if(i == 0)
		{
			for(j=0; s2[j]; j++);
		}
		printf("%d\n", max(i, j)-dp[i][j]);
	}
	return 0;
}
