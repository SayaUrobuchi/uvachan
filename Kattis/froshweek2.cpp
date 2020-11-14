#include <iostream>
#include <algorithm>

int ary[1048576], bry[1048576];

int main()
{
	int n, m, i, j, ans;
	while (scanf("%d%d", &n, &m) == 2)
	{
		for (i=0; i<n; i++)
		{
			scanf("%d", &ary[i]);
		}
		std::sort(ary, ary+n, std::greater<int>());
		for (i=0; i<m; i++)
		{
			scanf("%d", &bry[i]);
		}
		std::sort(bry, bry+m, std::greater<int>());
		for (i=0, j=0, ans=0; i<m&&j<n; i++)
		{
			for (; j<n&&ary[j]>bry[i]; j++);
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
