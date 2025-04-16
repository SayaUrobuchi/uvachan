#include <iostream>
using namespace std;

int calc(int y, int m, int d)
{
	int ret = 365 * y + y / 4 - y / 100 + y / 400;
	ret += 306*(m+1)/10 + d - 429;
	return ret;
}

int main()
{
	int y, m, d;
	scanf("%d%d%d", &y, &m, &d);
	if (m <= 2)
	{
		m += 12;
		--y;
	}
	int ans = calc(2014, 5, 17) - calc(y, m, d);
	printf("%d\n", ans);
	return 0;
}
