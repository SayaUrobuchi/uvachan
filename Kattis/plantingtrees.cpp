#include <iostream>
#include <algorithm>

int ary[1048576];

int main()
{
	int n, i, j, best;
	while (scanf("%d", &n) == 1)
	{
		for (i=0; i<n; i++)
		{
			scanf("%d", &ary[i]);
		}
		std::sort(ary, ary+n);
		for (i=0, j=n+1, best=ary[0]; i<n; i++, j--)
		{
			if (ary[i] + j > best)
			{
				best = ary[i] + j;
			}
		}
		printf("%d\n", best);
	}
	return 0;
}
