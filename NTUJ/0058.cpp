#include <stdio.h>
#include <stdlib.h>

int ary[1010], dp[1010];

int comp(const void *p, const void *q)
{
	return *(int*)p - *(int*)q;
}

int main()
{
	int n, m, i, j, k;
	while(scanf("%d%d", &m, &n) == 2)
	{
		if(m == -1 && n == -1)
		{
			break;
		}
		for(i=1; i<=n; i++)
		{
			scanf("%d", &ary[i]);
		}
		qsort(ary+1, n, sizeof(int), comp);
		for(i=1; i<=n; i++)
		{
			for(j=i-1; j>0&&ary[i]-m<=ary[j]; j--);
			for(k=j++; k>0&&ary[j]-m<=ary[k]; k--);
			dp[i] = dp[k] + 1;
		}
		printf("%d\n", dp[n]);
	}
	return 0;
}
