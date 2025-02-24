#include <iostream>
using namespace std;

int f(int t)
{
	int ret = 0;
	while (t)
	{
		ret += t % 10;
		t /= 10;
	}
	return ret;
}

int main()
{
	int a, b;
	scanf("%d%d", &a, &b);
	int ans = max(f(a), f(b));
	printf("%d\n", ans);
	return 0;
}
