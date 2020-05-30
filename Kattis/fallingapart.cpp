#include <stdio.h>
#include <algorithm>

int ary[32], ans[8];

bool comp(int p, int q)
{
	return p>q;
}

int main()
{
	int n, i;
	while (scanf("%d", &n) == 1)
	{
		for (i=0; i<n; i++)
		{
			scanf("%d", &ary[i]);
		}
		std::sort(ary, ary+n, comp);
		for (i=0, ans[0]=ans[1]=0; i<n; i++)
		{
			ans[i&1] += ary[i];
		}
		printf("%d %d\n", ans[0], ans[1]);
	}
	return 0;
}
