#include <stdio.h>
#include <algorithm>

int ary[1024];

int main()
{
	int n, i, mm, nn;
	while (scanf("%d", &n) == 1)
	{
		for (i=0; i<n; i++)
		{
			scanf("%d", &ary[i]);
		}
		std::sort(ary, ary+n);
		mm = -1;
		nn = -1;
		for (i=0; i<n; i++)
		{
			printf("%d%c", ary[i], (i==n-1?'\n':' '));
			if (ary[i] < 60)
			{
				mm = ary[i];
			}
			if (ary[i] >= 60 && nn < 0)
			{
				nn = ary[i];
			}
		}
		if (mm < 0)
		{
			puts("best case");
		}
		else
		{
			printf("%d\n", mm);
		}
		if (nn < 0)
		{
			puts("worst case");
		}
		else
		{
			printf("%d\n", nn);
		}
	}
	return 0;
}
