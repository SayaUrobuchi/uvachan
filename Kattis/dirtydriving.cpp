#include <iostream>
#include <algorithm>

int ary[1048576];

int main()
{
	int n, m, i, ans;
	while (scanf("%d%d", &n, &m) == 2)
	{
		for (i=0; i<n; i++)
		{
			scanf("%d", &ary[i]);
		}
		std::sort(ary, ary+n);
		for (i=1, ans=ary[0]-m; i<n; i++)
		{
			ans = std::min(ans, ary[i]-m*(i+1));
		}
		printf("%d\n", ary[0]-ans);
	}
	return 0;
}
