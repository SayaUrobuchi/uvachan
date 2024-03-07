#include <iostream>
using namespace std;

const int N = 1005;

int ary[N];

int main()
{
	int n, i;
	scanf("%d", &n);
	for (i=0; i<n; i++)
	{
		int t, id;
		scanf("%d%d", &t, &id);
		ary[id] = t;
	}
	int ans = 0;
	int cur = 1;
	for (i=1; i<=n; i++, cur++)
	{
		if (ary[i] > cur)
		{
			ans += ary[i] - cur;
			cur = ary[i];
		}
	}
	printf("%d\n", ans);
	return 0;
}
