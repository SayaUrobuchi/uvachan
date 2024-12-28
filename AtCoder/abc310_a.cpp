#include <iostream>
using namespace std;

int main()
{
	int n, i, p, q;
	scanf("%d%d%d", &n, &p, &q);
	int mn = 2e9;
	for (i=0; i<n; i++)
	{
		int t;
		scanf("%d", &t);
		mn = min(mn, t);
	}
	int ans = min(p, q+mn);
	printf("%d\n", ans);
	return 0;
}
