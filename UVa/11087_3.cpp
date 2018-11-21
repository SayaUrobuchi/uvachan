#include <stdio.h>
#include <string.h>

int cc[501];
char tbl[20000001], tt[20000001];

int mod(int p, int q)
{
	if(p >= 0)
	{
		return p % q;
	}
	return (q+(p%q)) % q;
}

int main()
{
	int count, cas, n, k, i, r, t, tmp;
	long long res;
	cas = 0;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d%d", &n, &k);
		memset(tbl, 0, sizeof(tbl));
		memset(tt, 0, sizeof(tt));
		memset(cc, 0, sizeof(cc));
		for(i=0, res=0; i<n; i++)
		{
			scanf("%d", &r);
			t = r + 10000000;
			tmp = mod(r, k);
			if((tbl[t>>3] & (1<<(t%8))) == 0)
			{
				tbl[t>>3] += (1<<(t%8));
				cc[tmp]++;
			}
			else
			{
				if(((tt[t>>3] & (1<<(t%8))) == 0) && (tmp == 0 || tmp+tmp == k))
				{
					tt[t>>3] += (1<<(t%8));
					res++;
				}
			}
		}
		for(i=1; i+i<k; i++)
		{
			res += (long long)cc[i] * cc[k-i];
		}
		res += ((long long)cc[0] * (cc[0]-1)) / 2;
		if(i + i == k)
		{
			res += ((long long)cc[i] * (cc[i]-1)) / 2;
		}
		printf("Case %d: %lld\n", ++cas, res);
	}
	return 0;
}
