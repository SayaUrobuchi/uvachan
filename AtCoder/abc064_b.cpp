#include <iostream>
using namespace std;

int main()
{
	int n, i;
	scanf("%d", &n);
	int mx = -1;
	int mn = 2e9;
	for (i=0; i<n; i++)
	{
		int t;
		scanf("%d", &t);
		mx = max(mx, t);
		mn = min(mn, t);
	}
	int ans = mx - mn;
	printf("%d\n", ans);
	return 0;
}
