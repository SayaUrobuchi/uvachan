#include <iostream>
#include <algorithm>

int ary[1048576];

int main()
{
	int n, i, j, best;
	while (scanf("%d", &n) == 1)
	{
		if (n == 0)
		{
			break;
		}
		for (i=0; i<n; i++)
		{
			scanf("%d", &ary[i]);
		}
		std::sort(ary, ary+n);
		for (i=0, best=0; i<n; i=j)
		{
			for (j=i+1; j<n&&ary[i]==ary[j]; j++);
			if (j-i > best)
			{
				best = j-i;
			}
		}
		printf("%d\n", best);
		for (i=0; i<best; i++)
		{
			for (j=i; j<n; j+=best)
			{
				printf((j==i?"%d":" %d"), ary[j]);
			}
			puts("");
		}
	}
	return 0;
}
