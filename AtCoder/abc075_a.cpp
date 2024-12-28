#include <iostream>
using namespace std;

int main()
{
	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);
	int ans = c;
	if (a != b)
	{
		ans = a + b - c;
	}
	printf("%d\n", ans);
	return 0;
}
