#include <stdio.h>
#include <stdlib.h>

long long ary[2005];

int comp(const void *p, const void *q)
{
	return *(long long*)p - *(long long*)q;
}

int bisearch(int left, int right, long long target)
{
	int center;
	if(left > right)
	{
		return 0;
	}
	center = ((left + right) >> 1);
	if(ary[center]*ary[center] == target)
	{
		return 1;
	}
	else if(ary[center]*ary[center] > target)
	{
		return bisearch(left, center-1, target);
	}
	return bisearch(center+1, right, target);
}

int main()
{
	int n, i, j, ans;
	while(scanf("%d", &n) == 1)
	{
		for(i=0; i<n; i++)
		{
			scanf("%I64d", &ary[i]);
		}
		qsort(ary, n, sizeof(long long), comp);
		for(i=0, ans=0; i<n; i++)
		{
			for(j=i+1; j<n; j++)
			{
				ans += bisearch(j+1, n-1, ary[i]*ary[i]+ary[j]*ary[j]);
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
