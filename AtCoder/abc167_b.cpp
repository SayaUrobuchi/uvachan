#include <iostream>
using namespace std;

int main()
{
	int a, b, c, n;
	scanf("%d%d%d%d", &a, &b, &c, &n);
	int ans = min(a, n);
	n -= min(a, n);
	n -= min(b, n);
	ans -= n;
	printf("%d\n", ans);
	return 0;
}
