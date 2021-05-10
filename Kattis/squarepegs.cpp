#include <iostream>
#include <algorithm>

int ary[1024], bry[1024];

int main()
{
	int n, m, o, i, j, ans;
	while (scanf("%d%d%d", &n, &m, &o) == 3)
	{
		for (i=0; i<n; i++)
		{
			scanf("%d", &ary[i]);
			ary[i] *= ary[i] * 2;
		}
		std::sort(ary, ary+n);
		for (i=0; i<m; i++)
		{
			scanf("%d", &bry[i]);
			bry[i] *= bry[i] * 2;
		}
		for (i=m; i<m+o; i++)
		{
			scanf("%d", &bry[i]);
			bry[i] *= bry[i];
		}
		std::sort(bry, bry+m+o);
		for (i=0, j=0, ans=0; i<m+o; i++)
		{
			for (; j<n&&ary[j]<=bry[i]; j++);
			if (j < n)
			{
				++ans;
				++j;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
