#include <stdio.h>
#include <algorithm>

int a, b;
int ary[1048576];

long long recurs(int p, int q, int r, int s)
{
	int mid, t;
	long long res, res2;
	if (r > s)
	{
		return a;
	}
	if (p == q)
	{
		return b*(s-r+1);
	}
	res = (long long)b*(q-p+1)*(s-r+1);
	mid = ((p+q) >> 1);
	t = std::upper_bound(ary+r, ary+s+1, mid) - ary;
	res2 = recurs(p, mid, r, t-1) + recurs(mid+1, q, t, s);
	//printf("%d %d %d %d => %lld %lld\n", p, q, r, s, res, res2);
	return res2<res ? res2 : res;
}

int main()
{
	int n, m, i;
	while (scanf("%d%d%d%d", &m, &n, &a, &b) == 4)
	{
		for (i=0; i<n; i++)
		{
			scanf("%d", &ary[i]);
		}
		std::sort(ary, ary+n);
		printf("%lld\n", recurs(1, (1<<m), 0, n-1));
	}
	return 0;
}
