#include <iostream>
using namespace std;

const int L2 = 30;
const int L3 = 19;
const int L5 = 13;
const int L7 = 11;
const int DT[10][4] = {{}, {}, {1}, {0, 1}, {2}, {0, 0, 1}, {1, 1}, {0, 0, 0, 1}, {3}, {0, 2}};

long long dp[19][L2][L3][L5][L7];
char buf[128];

long long calc(long long n)
{
	long long t, u, y, ans;
	for (t=n/10, u=1, y=1, ans=n+1; y<=n; t/=10, u*=9, y*=10)
	{
		ans -= t * u;
		if (n/y%10)
		{
			ans -= u;
		}
		else
		{
			ans -= calc(n%y);
		}
	}
	//printf("calc %lld => %lld\n", n, ans);
	return ans;
}

long long rec(long long n)
{
	long long t, u, y, z, ans;
	for (t=n, u=1, y=10, ans=0; t>9; t/=10, u*=9, y*=10)
	{
		ans += max(0LL, t/10-1) * u;
		if (t%10)
		{
			ans += u;
		}
		else
		{
			if (u == 1 || n%(y/10))
			{
				ans += calc(n%(y/10));
			}
		}
	}
	//printf(".. %lld %lld\n", n, ans);
	return ans;
}

void dfs2(int depth, int w, int x, int y, int z, int t, long long cur, int m, long long &ans)
{
	if (cur > m)
	{
		return;
	}
	if (depth == 4 || t == 0)
	{
		ans += dp[t][w][x][y][z];
		return;
	}
	dfs2(depth+1, w, x, y, z, t, cur, m, ans);
	if (depth == 0)
	{
		cur <<= 1;
		++w;
	}
	else if (depth == 1)
	{
		cur *= 3;
		++x;
	}
	else if (depth == 2)
	{
		cur *= 5;
		++y;
	}
	else
	{
		cur *= 7;
		++z;
	}
	dfs2(depth, w, x, y, z, t, cur, m, ans);
}

void dfs(int depth, long long cur, int m, int len, long long &ans)
{
	int t, i;
	if (depth >= len)
	{
		if (cur <= m)
		{
			++ans;
		}
		return;
	}
	if (buf[depth] == '0')
	{
		return;
	}
	t = len - depth - 1;
	for (i=1; i+'0'<buf[depth]; i++)
	{
		dfs2(0, 0, 0, 0, 0, t, cur*i, m, ans);
	}
	dfs(depth+1, cur*(buf[depth]-'0'), m, len, ans);
}

int main()
{
	int m, i, j, k, p, q, r, len;
	long long n, ans;
	dp[0][0][0][0][0] = 1;
	for (i=1; i<=18; i++)
	{
		for (j=0; j<L2; j++)
		{
			for (k=0; k<L3; k++)
			{
				for (p=0; p<L5; p++)
				{
					for (q=0; q<L7; q++)
					{
						for (r=1; r<=9; r++)
						{
							if (j >= DT[r][0] && k >= DT[r][1] && p >= DT[r][2] && q >= DT[r][3])
							{
								dp[i][j][k][p][q] += dp[i-1][j-DT[r][0]][k-DT[r][1]][p-DT[r][2]][q-DT[r][3]];
							}
						}
					}
				}
			}
		}
	}
	while (scanf("%lld%d", &n, &m) == 2)
	{
		len = sprintf(buf, "%lld", n);
		ans = rec(n);
		//printf("zero: %lld\n", ans);
		dfs(0, 1, m, len, ans);
		//printf("full: %lld\n", ans);
		for (i=1; i<len; i++)
		{
			dfs2(0, 0, 0, 0, 0, i, 1, m, ans);
		}
		printf("%lld\n", ans);
	}
	return 0;
}

