#include <iostream>

const int T = 40;

int main()
{
	int a, b, c, d, ans;
	while (scanf("%d%d%d%d", &a, &b, &c, &d) == 4)
	{
		if (a == 0 && b == 0 && c == 0 && d == 0)
		{
			break;
		}
		ans = T+T+(a+T-b)%T;
		ans += T+(c+T-b)%T;
		ans += (c+T-d)%T;
		printf("%d\n", ans*9);
	}
	return 0;
}
