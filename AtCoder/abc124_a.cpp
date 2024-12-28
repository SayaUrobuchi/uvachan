#include <iostream>
using namespace std;

int main()
{
	int a, b;
	scanf("%d%d", &a, &b);
	int ans;
	if (a > b)
	{
		ans = a;
		--a;
	}
	else
	{
		ans = b;
		--b;
	}
	ans += max(a, b);
	printf("%d\n", ans);
	return 0;
}
