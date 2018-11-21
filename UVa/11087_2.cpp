#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int ary[100001];
long long tbl[505];

int comp(const void *p, const void *q)
{
	return *(int*)p - *(int*)q;
}

int mod(int p, int q)
{
	if(p < 0)
	{
		return (q-((-p)%q))%q;
	}
	else
	{
		return p%q;
	}
}

int main()
{
	int cas, count, n, m, i, j, temp
	long long ans;
	cas = 0;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d%d", &n, &m);
		for(i=0; i<n; i++)
		{
			scanf("%d", &ary[i]);
		}
		qsort(ary, n, sizeof(int), comp);
		memset(tbl, 0, sizeof(tbl));
		for(i=0, ans=0; i<n; i++)
		{
			if(!i || ary[i] != ary[i-1])
			{
				tbl[mod(ary[i], m)]++;
				if(i+1 < n && ary[i] == ary[i+1])
				{
					temp = mod(ary[i], m);
					if(temp+temp == m || !temp)
					{
						ans++;
					}
				}
			}
		}
		for(i=1, j=m-1; i<j; i++, j--)
		{
			ans += tbl[i] * tbl[j];
		}
		if(i == j)
		{
			ans += tbl[i] * (tbl[i]-1) / 2;
		}
		ans += tbl[0] * (tbl[0]-1) / 2;
		printf("Case %d: %lld\n", ++cas, ans);
	}
	return 0;
}
