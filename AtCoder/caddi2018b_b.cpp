#include <iostream>
using namespace std;

int main()
{
	int n, i, h, w;
	scanf("%d%d%d", &n, &h, &w);
	int ans = 0;
	for (i=0; i<n; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		ans += (a >= h && b >= w);
	}
	printf("%d\n", ans);
	return 0;
}