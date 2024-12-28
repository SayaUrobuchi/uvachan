#include <iostream>
using namespace std;

int main()
{
	freopen("teleport.in", "r", stdin);
	freopen("teleport.out", "w", stdout);
	int a, b, x, y;
	scanf("%d%d%d%d", &a, &b, &x, &y);
	int ans = abs(b - a);
	ans = min(ans, abs(x-a)+abs(y-b));
	ans = min(ans, abs(y-a)+abs(x-b));
	printf("%d\n", ans);
	return 0;
}
