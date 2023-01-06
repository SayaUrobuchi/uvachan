#include <iostream>
using namespace std;

int main()
{
	int a, b, c, x, y, z, ans;
	scanf("%d%d%d", &x, &y, &z);
	a = min(x, min(y, z));
	c = max(x, max(y, z));
	b = (x+y+z) - (a+c);
	ans = c-b;
	a += ans;
	ans += (c-a) >> 1;
	if ((a^c) & 1)
	{
		ans += 2;
	}
	printf("%d\n", ans);
	return 0;
}
