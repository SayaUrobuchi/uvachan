#include <stdio.h>
#include <string.h>

long long dp[20][20], n;
char chk[20][20];

long long max(long long p, long long q)
{
	if(p > q)
	{
		return p;
	}
	return q;
}

long long calc(int i, int j)
{
	long long k, temp, temp2;
	if(chk[i][j])
	{
		return dp[i][j];
	}
	if(i < j)
	{
		temp = calc(i, i) + calc(i+1, j);
		for(k=i+1; k<j; k++)
		{
			temp = max(temp, calc(i, k)+calc(k+1, j));
		}
		chk[i][j] = 1;
		return dp[i][j] = temp;
	}
	else
	{
		if(i < n)
		{
			temp = calc(i+1, 1) + calc(i+1, j);
			for(k=i+2; k<=n; k++)
			{
				temp = max(temp, calc(k, 1)+calc(k, j));
			}
		}
		else
		{
			temp = 0;
		}
		if(j > 1)
		{
			temp2 = calc(i, 1) + calc(n, 1);
			for(k=2; k<j; k++)
			{
				temp2 = max(temp2, calc(i, k)+calc(n, k));
			}
		}
		else
		{
			temp2 = 0;
		}
		chk[i][j] = 1;
		return dp[i][j] = temp + temp2;
	}
}

int main()
{
	int m;
	while(scanf("%d%d", &n, &m) == 2)
	{
		memset(chk, 0, sizeof(chk));
		chk[n][1] = 1;
		dp[n][1] = m;
		printf("%lld\n", calc(1, n));
	}
	return 0;
}
