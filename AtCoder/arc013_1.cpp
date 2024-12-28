#include <iostream>
using namespace std;

int main()
{
	int x, y, z, a, b, c;
	scanf("%d%d%d", &x, &y, &z);
	scanf("%d%d%d", &a, &b, &c);
	int ans = (x/a) * (y/b) * (z/c);
	ans = max(ans, (x/a) * (y/c) * (z/b));
	ans = max(ans, (x/b) * (y/a) * (z/c));
	ans = max(ans, (x/b) * (y/c) * (z/a));
	ans = max(ans, (x/c) * (y/a) * (z/b));
	ans = max(ans, (x/c) * (y/b) * (z/a));
	printf("%d\n", ans);
	return 0;
}
