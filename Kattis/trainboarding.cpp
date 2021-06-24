#include <iostream>
#include <algorithm>

int ary[1024];

int main()
{
	int n, m, o, i, t, d, cur, last, worst, best;
	while (scanf("%d%d%d", &n, &m, &o) == 3)
	{
		for (i=0; i<o; i++)
		{
			scanf("%d", &ary[i]);
		}
		std::sort(ary, ary+o);
		for (i=0, last=-1, worst=-1, best=-1, cur=0; i<o; i++)
		{
			t = ary[i] / m;
			if (t >= n)
			{
				t = n-1;
			}
			d = std::abs(ary[i]-(t*m+(m>>1)));
			if (d > worst)
			{
				worst = d;
			}
			if (t != last)
			{
				cur = 0;
				last = t;
			}
			++cur;
			if (cur > best)
			{
				best = cur;
			}
		}
		printf("%d\n%d\n", worst, best);
	}
	return 0;
}
