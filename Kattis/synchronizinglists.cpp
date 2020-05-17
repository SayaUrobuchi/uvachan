#include <stdio.h>
#include <algorithm>

const int N = 16384;

int ary[N], bry[N], idx[N], tbl[N];

int comp(int p, int q)
{
	return ary[p] < ary[q];
}

int main()
{
	int n, i;
	while (scanf("%d", &n) == 1)
	{
		if (n == 0)
		{
			break;
		}
		for (i=0; i<n; i++)
		{
			scanf("%d", &ary[i]);
			idx[i] = i;
		}
		std::sort(idx, idx+n, comp);
		for (i=0; i<n; i++)
		{
			scanf("%d", &bry[i]);
			tbl[idx[i]] = i;
		}
		std::sort(bry, bry+n);
		for (i=0; i<n; i++)
		{
			printf("%d\n", bry[tbl[i]]);
		}
		//puts("");
	}
	return 0;
}
