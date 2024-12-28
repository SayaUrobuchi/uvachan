#include <iostream>
using namespace std;

int main()
{
	int a, b, c, d, e;
	scanf("%d%d%d%d%d", &a, &b, &c, &d, &e);
	int ans = 0;
	if (a < 0)
	{
		ans += -a * c;
		a = 0;
	}
	if (a == 0)
	{
		ans += d;
	}
	ans += (b - a) * e;
	printf("%d\n", ans);
	return 0;
}
