#include <stdio.h>
#include <string.h>

int used[105], tbl[105];
int bal[105][4];
long long wei[105], gcc[105];

long long gcd(long long p, long long q)
{
	return p%q ? gcd(q, p%q) : q;
}

void calc(int t)
{
	long long lw, lg, rw, rg, gg, tlw, trw, tt;
	if(used[t])
	{
		return;
	}
	used[t] = 1;
	if(bal[t][2])
	{
		calc(bal[t][2]);
		lw = wei[bal[t][2]];
		lg = gcc[bal[t][2]];
	}
	else
	{
		lw = bal[t][1];
		lg = bal[t][1];
	}
	if(bal[t][3])
	{
		calc(bal[t][3]);
		rw = wei[bal[t][3]];
		rg = gcc[bal[t][3]];
	}
	else
	{
		rw = bal[t][0];
		rg = bal[t][0];
	}
	tlw = lw;
	trw = rw;
	if(lw * bal[t][1] != rw * bal[t][0])
	{
		gg = gcd(lw*bal[t][0], rw*bal[t][1]);
		tlw = lw * (tt=rw * bal[t][1] / gg);
		lg *= tt;
		trw = rw * (tt=lw * bal[t][0] / gg);
		rg *= tt;
	}
	wei[t] = tlw+trw;
	gcc[t] = gcd(lg, rg);
	/*printf("%d: %I64d %I64d\n", t, wei[t], gcc[t]);*/
}

int main()
{
	int n, i, res;
	while(scanf("%d", &n) == 1)
	{
		memset(tbl, 0, sizeof(tbl));
		for(i=1; i<=n; i++)
		{
			scanf("%d%d%d%d", &bal[i][0], &bal[i][1], &bal[i][2], &bal[i][3]);
			tbl[bal[i][2]] = tbl[bal[i][3]] = 1;
		}
		memset(used, 0, sizeof(used));
		for(i=1; i<=n; i++)
		{
			calc(i);
			if(tbl[i] == 0)
			{
				res = i;
			}
		}
		printf("%I64d\n", wei[res]/gcc[res]);
	}
	return 0;
}
