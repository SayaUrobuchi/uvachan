#include <iostream>
#include <algorithm>
using namespace std;

int ary[1048576];

int main()
{
	int n, m, o, i, a, b;
	long long ans;
	while (scanf("%d%d", &n, &o) == 2)
	{
		for (i=0, m=0; i<n; i++)
		{
			scanf("%d%d", &a, &b);
			ary[m++] = b;
			ary[m++] = a-b;
		}
		sort(ary, ary+m, greater<int>());
		for (i=0, ans=0; i<o; i++)
		{
			ans += ary[i];
		}
		printf("%lld\n", ans);
	}
	return 0;
}
