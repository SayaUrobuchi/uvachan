#include <iostream>
#include <algorithm>
using namespace std;

pair<int, int> ary[400010];
int ans[200005];

int main()
{
	int n, n2, i, j, t, a, b, last;
	while (scanf("%d", &n) == 1)
	{
		for (i=0; i<n; i++)
		{
			scanf("%d%d", &a, &b);
			ary[i].first = a;
			ary[i].second = 1;
			ary[i+n].first = a + b;
			ary[i+n].second = -1;
		}
		n2 = (n << 1);
		sort(ary, ary+n2);
		fill(ans, ans+n+1, 0);
		for (i=0, t=0, last=ary[0].first; i<n2; i=j)
		{
			ans[t] += ary[i].first - last;
			for (j=i; j<n2&&ary[j].first==ary[i].first; j++)
			{
				t += ary[j].second;
			}
			last = ary[i].first;
		}
		printf("%d", ans[1]);
		for (i=2; i<=n; i++)
		{
			printf(" %d", ans[i]);
		}
		puts("");
	}
	return 0;
}