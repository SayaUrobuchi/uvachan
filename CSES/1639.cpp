#include <iostream>
using namespace std;

int dp[5050][5050];
char sa[5050], sb[5050];

int main()
{
	int i, j;
	while (scanf("%s%s", sa+1, sb+1) == 2)
	{
		for (i=1; sa[i]; i++)
		{
			dp[i][0] = i;
		}
		for (i=1; sb[i]; i++)
		{
			dp[0][i] = i;
		}
		for (i=1; sa[i]; i++)
		{
			for (j=1; sb[j]; j++)
			{
				dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + 1;
				if (sa[i] == sb[j])
				{
					dp[i][j] = min(dp[i][j], dp[i-1][j-1]);
				}
				else
				{
					dp[i][j] = min(dp[i][j], dp[i-1][j-1]+1);
				}
			}
		}
		printf("%d\n", dp[i-1][j-1]);
	}
	return 0;
}

