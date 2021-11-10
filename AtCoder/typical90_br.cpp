#include <iostream>
#include <algorithm>
using namespace std;

int px[1048576], py[1048576];

int main()
{
	int n, i;
	long long ans;
	while (scanf("%d", &n) == 1)
	{
		for (i=0; i<n; i++)
		{
			scanf("%d%d", &px[i], &py[i]);
		}
		sort(px, px+n);
		sort(py, py+n);
		for (i=0, ans=0; i<n; i++)
		{
			ans += (long long)abs(px[i]-px[n>>1]) + abs(py[i]-py[n>>1]);
		}
		printf("%lld\n", ans);
	}
	return 0;
}
