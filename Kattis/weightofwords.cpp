#include <iostream>

bool dp[64][1024];
int from[64][1024];

int main()
{
	int n, m, i, j, k;
	dp[0][0] = true;
	for (i=1; i<=40; i++)
	{
		for (j=1; j<=1000; j++)
		{
			for (k=1; k<=26&&k<=j; k++)
			{
				if (dp[i-1][j-k])
				{
					dp[i][j] = true;
					from[i][j] = k;
					break;
				}
			}
		}
	}
	while (scanf("%d%d", &n, &m) == 2)
	{
		if (!dp[n][m])
		{
			puts("impossible");
			continue;
		}
		for (; n>0; m-=from[n][m], --n)
		{
			putchar('a'+from[n][m]-1);
		}
		puts("");
	}
	return 0;
}
