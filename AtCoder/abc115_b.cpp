#include <iostream>
using namespace std;

int main()
{
	int n, i;
	scanf("%d", &n);
	int ans = 0;
	int mx = 0;
	for (i=0; i<n; i++)
	{
		int t;
		scanf("%d", &t);
		ans += t;
		mx = max(mx, t);
	}
	ans -= (mx >> 1);
	printf("%d\n", ans);
	return 0;
}
