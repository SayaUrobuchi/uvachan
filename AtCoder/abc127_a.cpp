#include <iostream>
using namespace std;

int main()
{
	int a, b;
	scanf("%d%d", &a, &b);
	int ans = 0;
	if (a >= 13)
	{
		ans = b;
	}
	else if (a >= 6)
	{
		ans = b / 2;
	}
	printf("%d\n", ans);
	return 0;
}
