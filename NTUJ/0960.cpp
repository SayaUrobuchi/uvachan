#include <stdio.h>

long long c[35][35];

long long f(int n)
{
	int i, j, k, t;
	long long res;
	res = 0;
	for(i=1; i<32; i++)
	{
		for(j=31, k=i, t=n; j>=0&&k>=0; j--)
		{
			if(t >= (1ll<<j))
			{
				res += c[j][k] * i;
				//printf("%d %I64d\n", i, res);
				k--;
				t -= (1ll<<j);
				if(k == 0 && t == 0)
				{
					res += i;
					break;
				}
			}
		}
	}
	return res;
}

int main()
{
	int cas, n, m, i, j;
	cas = 0;
	c[0][0] = 1;
	for(i=1; i<33; i++)
	{
		c[i][0] = 1;
		for(j=1; j<33; j++)
		{
			c[i][j] = c[i-1][j-1] + c[i-1][j];
		}
	}
	while(scanf("%d%d", &n, &m) == 2)
	{
		if(n == 0 && m == 0)
		{
			break;
		}
		printf("Case %d: %lld\n", ++cas, f(m)-f(n-1));
	}
	return 0;
}
