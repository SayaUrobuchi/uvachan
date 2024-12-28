#include <iostream>
using namespace std;

int main()
{
	int n, a, b, c, d;
	scanf("%d%d%d%d%d", &n, &a, &b, &c, &d);
	int x = (a + c - 1) / c;
	int y = (b + d - 1) / d;
	int ans = n - max(x, y);
	printf("%d\n", ans);
	return 0;
}
