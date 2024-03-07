#include <iostream>
using namespace std;

const int N = 1000005;

int ary[N];

int main()
{
	int n, m, i, j;
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
		int ans = 0;
		for (i=0, j=0; i<m; i++)
		{
			int t;
			scanf("%d", &t);
			for (; j<n&&ary[j]<t; j++);
			if (j < n && ary[j] == t)
			{
				++ans;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
