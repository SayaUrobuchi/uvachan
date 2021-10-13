#include <iostream>
#include <algorithm>
using namespace std;

int ary[1048576], bry[1048576];

int main()
{
	int n, i;
	long long ans;
	while (scanf("%d", &n) == 1)
	{
		for (i=0; i<n; i++)
		{
			scanf("%d", &ary[i]);
		}
		for (i=0; i<n; i++)
		{
			scanf("%d", &bry[i]);
		}
		sort(ary, ary+n);
		sort(bry, bry+n);
		for (i=0, ans=0; i<n; i++)
		{
			ans += abs(ary[i]-bry[i]);
		}
		printf("%lld\n", ans);
	}
	return 0;
}
