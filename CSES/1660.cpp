#include <iostream>
using namespace std;

int ary[262144];

int main()
{
	int n, m, i, j, ans, sum;
	while (scanf("%d%d", &n, &m) == 2)
	{
		for (i=0; i<n; i++)
		{
			scanf("%d", &ary[i]);
		}
		for (i=0, j=0, ans=0, sum=0; i<n; i++)
		{
			for (; j<n&&sum+ary[j]<=m; sum+=ary[j], j++);
			if (sum == m)
			{
				++ans;
			}
			sum -= ary[i];
		}
		printf("%d\n", ans);
	}
	return 0;
}

