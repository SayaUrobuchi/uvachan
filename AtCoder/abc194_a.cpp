#include <iostream>
using namespace std;

int main()
{
	int a, b;
	scanf("%d%d", &a, &b);
	int ans = 4;
	if (a+b >= 15 && b >= 8)
	{
		ans = 1;
	}
	else if (a+b >= 10 && b >= 3)
	{
		ans = 2;
	}
	else if (a+b >= 3)
	{
		ans = 3;
	}
	printf("%d\n", ans);
	return 0;
}
