#include <iostream>
using namespace std;

long long c[64][64], dp[64][64];
char s[64];

int main()
{
	int n, m, len, i, j, k;
	long long o;
	c[0][0] = 1;
	for (i=1; i<=60; i++)
	{
		c[i][0] = 1;
		for (j=1; j<=i; j++)
		{
			c[i][j] = c[i-1][j] + c[i-1][j-1];
		}
	}
	dp[0][0] = 1;
	for (i=1; i<=60; i++)
	{
		dp[0][i] = dp[i][0] = 1;
		for (j=1, k=i-j; j<i; j++, k--)
		{
			dp[j][k] = c[j+k][j];
		}
	}
	while (scanf("%d%d%lld", &n, &m, &o) == 3)
	{
		len = n + m;
		for (i=0; i<len; i++)
		{
			if (n && dp[n-1][m] >= o)
			{
				s[i] = 'a';
				--n;
			}
			else
			{
				s[i] = 'b';
				o -= dp[n-1][m];
				--m;
			}
		}
		s[len] = 0;
		puts(s);
	}
	return 0;
}

