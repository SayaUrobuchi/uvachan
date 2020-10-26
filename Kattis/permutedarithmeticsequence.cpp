#include <iostream>
#include <algorithm>

int ary[1048576];

int main()
{
	int count, n, i, st;
	scanf("%d", &count);
	while (count--)
	{
		scanf("%d", &n);
		for (i=0, st=0; i<n; i++)
		{
			scanf("%d", &ary[i]);
			if (i >= 2 && !st)
			{
				if (ary[i]-ary[i-1] != ary[1]-ary[0])
				{
					st = 1;
				}
			}
		}
		if (st == 1)
		{
			std::sort(ary, ary+n);
			for (i=2; i<n&&st==1; i++)
			{
				if (ary[i]-ary[i-1] != ary[1]-ary[0])
				{
					st = 2;
					break;
				}
			}
		}
		if (st == 0)
		{
			puts("arithmetic");
		}
		else if (st == 1)
		{
			puts("permuted arithmetic");
		}
		else
		{
			puts("non-arithmetic");
		}
	}
	return 0;
}
