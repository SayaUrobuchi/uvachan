#include <stdio.h>
#include <algorithm>

int ary[100005];

int main()
{
	int count, n, m, i, j, rg, l, r, c, ans;
	scanf("%d", &count);
	while (count--)
	{
		scanf("%d%d", &m, &n);
		for (i=0; i<n; i++)
		{
			scanf("%d", &ary[i]);
		}
		std::sort(ary, ary+n);
		for (l=0, r=1000000; l<=r; )
		{
			c = ((l+r) >> 1);
			for (i=1, j=1, rg=ary[0]+c; i<n&&j<=m; i++)
			{
				if (ary[i] > rg)
				{
					rg = ary[i]+c;
					++j;
				}
			}
			if (j > m)
			{
				l = c+1;
			}
			else
			{
				ans = c;
				r = c-1;
			}
		}
		printf("%d.%d\n", ans>>1, 5*(ans&1));
	}
	return 0;
}
