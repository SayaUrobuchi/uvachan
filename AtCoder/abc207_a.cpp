#include <iostream>
using namespace std;

int main()
{
	int a, b, c, ans;
	while (scanf("%d%d%d", &a, &b, &c) == 3)
	{
		ans = a + b + c;
		if (a <= b && a <= c)
		{
			ans -= a;
		}
		else if (b <= a && b <= c)
		{
			ans -= b;
		}
		else
		{
			ans -= c;
		}
		printf("%d\n", ans);
	}
	return 0;
}
