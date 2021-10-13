#include <iostream>
#include <algorithm>
using namespace std;

int ary[4];

int main()
{
	int n, i, j, t, ans;
	while (scanf("%d%d%d%d", &n, &ary[0], &ary[1], &ary[2]) == 4)
	{
		sort(ary, ary+3, greater<int>());
		ans = 1e9;
		for (i=n/ary[0]; i>=0; i--)
		{
			t = n-ary[0]*i;
			for (j=t/ary[1]; j>=0; j--)
			{
				if ((t-ary[1]*j) % ary[2] == 0)
				{
					ans = min(ans, i+j+(t-ary[1]*j)/ary[2]);
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
