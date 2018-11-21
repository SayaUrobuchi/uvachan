#include <stdio.h>

int ary[1000000], tbl[1000000];

int max(int p, int q)
{
	if(p > q)
	{
		return p;
	}
	return q;
}

int min(int p, int q)
{
	if(p < q)
	{
		return p;
	}
	return q;
}

int main()
{
	int count, n, i, lim, ans;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d%d", &n, &ary[0]);
		tbl[0] = ary[0];
		for(i=1; i<n; i++)
		{
			scanf("%d", &ary[i]);
			tbl[i] = max(tbl[i-1], ary[i]);
		}
		for(i=n-2, lim=ary[n-1], ans=0; i>0; i--)
		{
			if(lim > ary[i] && tbl[i-1] < ary[i])
			{
				ans++;
			}
			lim = min(ary[i], lim);
		}
		printf("%d\n", ans);
	}
	return 0;
}
