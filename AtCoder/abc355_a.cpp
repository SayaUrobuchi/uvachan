#include <iostream>
using namespace std;

int main()
{
	int a, b;
	scanf("%d%d", &a, &b);
	int ans = -1;
	if (a != b)
	{
		ans = 6 - a - b;
	}
	printf("%d\n", ans);
	return 0;
}
