#include <iostream>
#include <cstring>

long long dp[32][2][32];
int jmp[1024];
char s[1024], buf[1024];

int main()
{
	int m, sn, len, i, j, k, t, p, q, r, st, ed;
	long long n, ans;
	while (scanf("%lld%d", &n, &m) == 2)
	{
		sprintf(s, "%lld", n);
		for (sn=0; s[sn]; ++sn);
		sprintf(buf, "%lld", (1LL<<m));
		for (len=0; buf[len]; ++len);
		jmp[0] = -1;
		for (i=1, j=0; i<len; i++, j++)
		{
			jmp[i] = j;
			while (j >= 0 && buf[i] != buf[j])
			{
				j = jmp[j];
			}
		}
		for (i=0, ans=0; i<=sn; i++)
		{
			memset(dp, 0, sizeof(dp));
			dp[0][0][0] = 1;
			for (j=0, k=0; j<i; j++)
			{
				t = s[j];
				for (p=0; p<2; p++)
				{
					for (q=0; q<len; q++)
					{
						for (r=q; r>=0&&t!=buf[r]; r=jmp[r]);
						if (r+1 < len)
						{
							dp[j+1][p][r+1] += dp[j][p][q];
						}
						else
						{
							dp[j+1][1][jmp[r]+1] += dp[j][p][q];
						}
					}
				}
			}
			for (j=i; j<sn; j++)
			{
				st = '0';
				if (j == i)
				{
					ed = s[j]-1;
				}
				else
				{
					ed = '9';
				}
				for (t=st; t<=ed; t++)
				{
					for (p=0; p<2; p++)
					{
						for (q=0; q<len; q++)
						{
							for (r=q; r>=0&&t!=buf[r]; r=jmp[r]);
							if (r+1 < len)
							{
								dp[j+1][p][r+1] += dp[j][p][q];
							}
							else
							{
								dp[j+1][1][jmp[r]+1] += dp[j][p][q];
							}
						}
					}
				}
			}
			for (q=0; q<len; q++)
			{
				ans += dp[sn][1][q];
			}
			//printf("%d: %lld\n", i, ans);
		}
		printf("%lld\n", ans);
	}
	return 0;
}
