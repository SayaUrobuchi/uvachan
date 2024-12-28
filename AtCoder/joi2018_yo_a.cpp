#include <iostream>
using namespace std;

int main()
{
	int n, a, b, c, d;
	scanf("%d%d%d%d%d", &n, &a, &b, &c, &d);
	int x = (n + a - 1) / a * b;
	int y = (n + c - 1) / c * d;
	int ans = min(x, y);
	printf("%d\n", ans);
	return 0;
}
