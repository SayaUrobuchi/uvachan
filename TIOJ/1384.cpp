#include <stdio.h>
#include <stdlib.h>

int t[100005], h[100005], dp[100005], id[100005];

int comp(const void *p, const void *q)
{
	if(t[*(int*)p] == t[*(int*)q])
	{
		return h[*(int*)p] - h[*(int*)q];
	}
	return t[*(int*)p] - t[*(int*)q];
}

int main()
{
	int n, m, i, j, now;
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
			for(j=m-1; j>=0&&h[dp[j]]>h[now]; j--);
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
