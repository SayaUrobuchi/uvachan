#include <iostream>
#include <algorithm>
using namespace std;

int ary[262144], bry[262144];

int main()
{
	int n, m, i, j, ans;
	while (scanf("%d%d", &n, &m) == 2)
	{
		for (i=0; i<n; i++)
		{
			scanf("%d", &ary[i]);
		}
		sort(ary, ary+n);
		for (j=0; j<m; j++)
		{
			scanf("%d", &bry[j]);
		}
		sort(bry, bry+m);
		for (i=0, j=0, ans=2e9; i<n; i++)
		{
			for (; j<m&&bry[j]<ary[i]; j++);
			if (j < m)
			{
				ans = min(ans, abs(bry[j]-ary[i]));
			}
			if (j-1 >= 0)
			{
				ans = min(ans, abs(bry[j-1]-ary[i]));
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}

