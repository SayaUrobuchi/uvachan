#include <iostream>
#include <algorithm>

int ary[1048576];

int main()
{
	int n, m, i;
	while (scanf("%d%d", &n, &m) == 2)
	{
		for (i=1; i<=n; i++)
		{
			scanf("%d", &ary[i]);
		}
		std::sort(ary+1, ary+n+1);
		for (i=2; i<=n&&ary[i]+ary[i-1]<=m; i++);
		printf("%d\n", i-1);
	}
	return 0;
}
