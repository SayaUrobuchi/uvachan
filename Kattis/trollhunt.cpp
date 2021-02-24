#include<iostream>
using namespace std;

int main()
{
	int a, b, c, ans;
	while (scanf("%d%d%d", &a, &b, &c) == 3)
	{
		b /= c;
		--a;
		ans = a / b;
		if (a % b)
		{
			++ans;
		}
		if (ans == 0)
		{
			ans = 1;
		}
		printf("%d\n", ans);
	}
	return 0;
}
