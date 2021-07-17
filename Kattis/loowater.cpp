#include <iostream>
#include <algorithm>

int ary[1048576], bry[1048576];

int main()
{
	int n, m, i, j;
	long long ans;
	while (scanf("%d%d", &n, &m) == 2)
	{
		if (n == 0 && m == 0)
		{
			break;
		}
		for (i=0; i<n; i++)
		{
			scanf("%d", &ary[i]);
		}
		std::sort(ary, ary+n);
		for (i=0; i<m; i++)
		{
			scanf("%d", &bry[i]);
		}
		std::sort(bry, bry+m);
		for (i=0, j=0, ans=0; i<n; i++)
		{
			for (; j<m&&bry[j]<ary[i]; j++);
			if (j >= m)
			{
				break;
			}
			ans += bry[j];
			++j;
		}
		if (i < n)
		{
			puts("Loowater is doomed!");
		}
		else
		{
			printf("%lld\n", ans);
		}
	}
	return 0;
}
