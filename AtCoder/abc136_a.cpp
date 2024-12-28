#include <iostream>
using namespace std;

int main()
{
	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);
	int passed = min(c, a-b);
	int ans = c - passed;
	printf("%d\n", ans);
	return 0;
}
