#include <stdio.h>
#include <algorithm>

int ary[1048576];

int main()
{
	int n, m, i, p, q, t, res, mid;
	while (scanf("%d", &n) == 1)
	{
		for (i=0; i<n; i++)
		{
			scanf("%d", &ary[i]);
		}
		std::sort(ary, ary+n);
		scanf("%d", &m);
		while (m--)
		{
			scanf("%d", &t);
			res = -1;
			for (p=0, q=n-1; p<=q; )
			{
				mid = ((p+q) >> 1);
				if (ary[mid] <= t)
				{
					res = mid;
					p = mid + 1;
				}
				else
				{
					q = mid - 1;
				}
			}
			if (res >= 0 && ary[res] == t)
			{
				printf("%d\n", t);
			}
			else
			{
				if (res < 0)
				{
					printf("no");
				}
				else
				{
					printf("%d", ary[res]);
				}
				++res;
				if (res >= n)
				{
					printf(" no\n");
				}
				else
				{
					printf(" %d\n", ary[res]);
				}
			}
		}
	}
	return 0;
}
