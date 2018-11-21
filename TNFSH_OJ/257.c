#include <stdio.h>
#include <string.h>

int loc[4][4005], llen[4];
int tbl[128];
int dp[4005], dlen;
char p[4005], q[4005];

int gcd(int a, int b)
{
	while((a %= b) && (b %= a));
	return a+b;
}

int main()
{
	int i, j, l, t, u, v;
	tbl['A'] = 0;
	tbl['T'] = 1;
	tbl['G'] = 2;
	tbl['C'] = 3;
	while(scanf("%s%s", &p, &q) == 2)
	{
		memset(llen, 0, sizeof(llen));
		for (i=0; p[i]; i++)
		{
			t = tbl[p[i]];
			loc[t][llen[t]++] = i;
		}
		l = i;
		dp[0] = -1;
		dlen = 0;
		for (i=0; q[i]; i++)
		{
			t = tbl[q[i]];
			v = dlen;
			for (j=llen[t]-1; j>=0; j--)
			{
				u = loc[t][j];
				while(u <= dp[v])
				{
					v--;
				}
				dp[v+1] = u;
				if (v == dlen)
				{
					dlen++;
				}
			}
		}
		l += i;
		dlen <<= 1;
		if (dlen == 0)
		{
			puts("0/1");
			//printf("0/%d\n", l);
		}
		else
		{
			v = gcd(dlen, l);
			printf("%d/%d\n", dlen/v, l/v);
		}
	}
	return 0;
}