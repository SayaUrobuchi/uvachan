#include <iostream>
#include <cstring>

long long dp[32][32];
int jmp[1024], stat[1024];
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
        int least = 0;
        for (i=0, j=0; i<sn; i++, j++)
        {
        	if (j == len)
        	{
        		least = len;
        	}
        	else
        	{
	        	while (j >= 0 && s[i] != buf[j])
	        	{
	        		j = jmp[j];
	        	}
	        }
        	stat[i+1] = std::max(least, j + 1);
        }
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;
        for (i=1; i<=sn; i++)
        {
        	for (j=0; j<len; j++)
        	{
        		for (k=0; k<=9; k++)
        		{
        			int t = j;
        			while (t >= 0 && '0'+k != buf[t])
        			{
        				t = jmp[t];
        			}
        			dp[i][t+1] += dp[i-1][j];
        			if (j == stat[i-1] && '0'+k > s[i-1])
        			{
        				--dp[i][t+1];
        			}
        		}
        	}
        }
        long long ans = 0;
        for (j=0; j<len; j++)
        {
        	ans += dp[sn][j];
        }
        printf("%lld\n", n+1-ans);
    }
    return 0;
}