#include <iostream>

int dp[4096][4096];
char s[4096], t[4096];

void recurs(int a, int b)
{
	if (!a || !b)
	{
		return;
	}
	if (s[a] == t[b])
	{
		recurs(a-1, b-1);
		putchar(s[a]);
	}
	else
	{
		if (dp[a][b] == dp[a-1][b])
		{
			recurs(a-1, b);
		}
		else
		{
			recurs(a, b-1);
		}
	}
}

int main()
{
	int i, j;
	while (scanf("%s%s", s+1, t+1) == 2)
	{
		for (i=1; s[i]; i++)
		{
			for (j=1; t[j]; j++)
			{
				if (s[i] == t[j])
				{
					dp[i][j] = dp[i-1][j-1] + 1;
				}
				else
				{
					dp[i][j] = std::max(dp[i-1][j], dp[i][j-1]);
				}
			}
		}
		recurs(i-1, j-1);
		puts("");
	}
	return 0;
}
