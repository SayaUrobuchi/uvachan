#include <iostream>
using namespace std;

int main()
{
	int a, b, c, d;
	scanf("%d%d%d%d", &a, &b, &c, &d);
	int dx = abs(a-c);
	int dy = abs(b-d);
	int ans = 0;
	if (dx + dy > 0)
	{
		if (dx == dy)
		{
			ans = 1;
		}
		else if (dx + dy <= 3)
		{
			ans = 1;
		}
		else if (abs(dx-dy) <= 3 || dx + dy <= 6)
		{
			ans = 2;
		}
		else if ((dx & 1) == (dy & 1))
		{
			ans = 2;
		}
		else
		{
			ans = 3;
		}
	}
	printf("%d\n", ans);
	return 0;
}
