#include <stdio.h>
#include <string.h>

int tbl[1000001];

int min(int p, int q)
{
	if(p < q)
	{
		return p;
	}
	return q;
}

int max(int p, int q)
{
	if(p > q)
	{
		return p;
	}
	return q;
}

int main()
{
	int n, m, i, minp, maxp, temp;
	long long total;
	while(scanf("%d", &n) == 1)
	{
		if(!n)
		{
			break;
		}
		memset(tbl, 0, sizeof(tbl));
		for(i=0, minp=2147483640, maxp=-1, total=0; i<n; i++)
		{
			scanf("%d", &m);
			while(m--)
			{
				scanf("%d", &temp);
				minp = min(temp, minp);
				maxp = max(temp, maxp);
				tbl[temp]++;
			}
			for(; !tbl[minp]; minp++);
			tbl[minp]--;
			for(; !tbl[maxp]; maxp--);
			tbl[maxp]--;
			total += maxp - minp;
		}
		printf("%lld\n", total);
	}
	return 0;
}
