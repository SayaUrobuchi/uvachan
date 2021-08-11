#include <iostream>

int dp[1024][1024];
char s[1024], key[1024];

int main()
{
	int i, j, ans;
	for (i=1, j='a'; j<='z'; i++, j++)
	{
		key[i] = j;
	}
	key[i] = 0;
	while (scanf("%s", s+1) == 1)
	{
		for (i=1, ans=0; s[i]; i++)
		{
			for (j=1; key[j]; j++)
			{
				if (s[i] == key[j])
				{
					dp[i][j] = dp[i-1][j-1] + 1;
				}
				else
				{
					dp[i][j] = std::max(dp[i-1][j], dp[i][j-1]);
				}
				ans = dp[i][j];
			}
		}
		printf("%d\n", 26-ans);
	}
	return 0;
}
