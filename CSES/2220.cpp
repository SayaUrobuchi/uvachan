#include <iostream>
#include <cstring>
using namespace std;

const int MX = 20;
const int BASE = 10;

long long dp[MX][BASE], sum[MX];

void precalc()
{
	int i, j;
	sum[0] = 1;
	for (i=0; i<BASE; i++)
	{
		dp[1][i] = 1;
		sum[1] += dp[1][i];
	}
	for (i=2; i<MX; i++)
	{
		for (j=0; j<BASE; j++)
		{
			dp[i][j] = sum[i-1] - dp[i-1][j];
			sum[i] += dp[i][j];
		}
	}
}

long long calc_len(int len)
{
	if (len == 0)
	{
		return 0;
	}
	return sum[len] - (len > 1 ? dp[len][0] : 0);
}

long long calc(long long n)
{
	int i, j, last;
	long long res;
	bool flag;
	char s[MX];
	sprintf(s, "%lld", n);
	int len = strlen(s);
	if (n < 0)
	{
		return 0LL;
	}
	if (n == 0)
	{
		return 1LL;
	}
	res = 0;
	for (i=0, last=-1, flag=true; s[i]; i++)
	{
		int cur = s[i] - '0';
		if (flag)
		{
			for (j=(i?0:1); j<cur; j++)
			{
				if (j != last)
				{
					res += sum[len-i-1] - dp[len-i-1][j];
					//printf("add %.*s%d~ totally %lld\n", i, s, j, sum[len-i-1] - dp[len-i-1][j]);
				}
			}
		}
		res += calc_len(len-i-1);
		//printf("add len %d all, totally %lld\n", len-i-1, calc_len(len-i-1));
		if (cur == last)
		{
			flag = false;
		}
		last = cur;
	}
	res += flag;
	//printf("original %lld +1\n", n);
	if (n < 10)
	{
		++res;
		//printf("add missing 0\n");
	}
	//printf("%lld ans %lld\n", n, res);
	return res;
}

int main()
{
	long long a, b;
	scanf("%lld%lld", &a, &b);
	precalc();
	printf("%lld\n", calc(b)-calc(a-1));
	return 0;
}
