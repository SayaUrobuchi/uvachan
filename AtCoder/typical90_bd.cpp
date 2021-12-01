#include <iostream>
using namespace std;

int ary[128][2];
int from[128][131072];
bool dp[128][131072];

void recurs(int a, int b)
{
	if (a > 1)
	{
		recurs(a-1, b-ary[a][from[a][b]]);
	}
	putchar('A'+from[a][b]);
}

int main()
{
	int n, m, i, j, k;
	while (scanf("%d%d", &n, &m) == 2)
	{
		dp[0][0] = true;
		for (i=1; i<=n; i++)
		{
			scanf("%d%d", &ary[i][0], &ary[i][1]);
			for (j=0; j<=m; j++)
			{
				dp[i][j] = false;
				for (k=0; k<2; k++)
				{
					if (j >= ary[i][k] && dp[i-1][j-ary[i][k]])
					{
						dp[i][j] = true;
						from[i][j] = k;
						break;
					}
				}
			}
		}
		if (dp[n][m])
		{
			recurs(n, m);
			puts("");
		}
		else
		{
			puts("Impossible");
		}
	}
	return 0;
}
