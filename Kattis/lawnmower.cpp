#include <iostream>
#include <algorithm>

double ary[1048576];

int main()
{
	int n, m, i;
	double last, w;
	bool gg;
	while (scanf("%d%d%lf", &n, &m, &w) == 3)
	{
		if (n == 0 && m == 0 && w == 0)
		{
			break;
		}
		w /= 2;
		for (i=0; i<n; i++)
		{
			scanf("%lf", &ary[i]);
		}
		std::sort(ary, ary+n);
		for (i=0, last=0; i<n; i++)
		{
			if (ary[i]-w > last)
			{
				break;
			}
			last = ary[i] + w;
		}
		gg = (last < 75);
		for (i=0; i<m; i++)
		{
			scanf("%lf", &ary[i]);
		}
		if (!gg)
		{
			std::sort(ary, ary+m);
			for (i=0, last=0; i<m; i++)
			{
				if (ary[i]-w > last)
				{
					break;
				}
				last = ary[i] + w;
			}
			gg = (last < 100);
		}
		if (gg)
		{
			puts("NO");
		}
		else
		{
			puts("YES");
		}
	}
	return 0;
}
