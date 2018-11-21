#include <stdio.h>
#include <stdlib.h>

int t[100005], h[100005], dp[100005], id[100005], j;

int comp(const void *p, const void *q)
{
	if(t[*(int*)p] == t[*(int*)q])
	{
		return h[*(int*)p] - h[*(int*)q];
	}
	return t[*(int*)p] - t[*(int*)q];
}

void bisearch(int p, int q, int hh)
{
	int center;
	if(p > q)
	{
		return;
	}
	center = ((p+q) >> 1);
	if(hh < h[dp[center]])
	{
		bisearch(p, center - 1, hh);
	}
	else
	{
		j = center;
		bisearch(center+1, q, hh);
	}
}

int main()
{
	int n, m, i, now;
	while(scanf("%d", &n) == 1)
	{
		for(i=0; i<n; i++)
		{
			scanf("%d%d", &t[i], &h[i]);
			id[i] = i;
		}
		qsort(id, n, sizeof(int), comp);
		for(i=0, m=0; i<n; i++)
		{
			now = id[i];
			j = -1;
			bisearch(0, m-1, h[now]);
			dp[++j] = now;
			if(j >= m)
			{
				m++;
			}
		}
		printf("%d\n", n-m);
	}
	return 0;
}
