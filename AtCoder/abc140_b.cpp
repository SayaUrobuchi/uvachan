#include <iostream>
using namespace std;

const int N = 32;

int ord[N], ary[N], ext[N];

int main()
{
	int n, i;
	scanf("%d", &n);
	for (i=1; i<=n; i++)
	{
		scanf("%d", &ord[i]);
	}
	for (i=1; i<=n; i++)
	{
		scanf("%d", &ary[i]);
	}
	for (i=1; i<n; i++)
	{
		scanf("%d", &ext[i]);
	}
	int last = -10;
	int ans = 0;
	for (i=1; i<=n; i++)
	{
		int cur = ord[i];
		ans += ary[cur];
		if (cur == last + 1)
		{
			ans += ext[last];
		}
		last = cur;
	}
	printf("%d\n", ans);
	return 0;
}
