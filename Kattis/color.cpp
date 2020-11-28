#include <iostream>
#include <algorithm>

int ary[1048576];

int main()
{
	int n, m, o, i, j, ans;
	while (scanf("%d%d%d", &n, &m, &o) == 3)
	{
		for (i=0; i<n; i++)
		{
			scanf("%d", &ary[i]);
		}
		std::sort(ary, ary+n);
		for (i=0, ans=0; i<n; ans++, i=j)
		{
			for (j=i+1; j<n&&j-i<m&&ary[j]-ary[i]<=o; j++);
		}
		printf("%d\n", ans);
	}
	return 0;
}
