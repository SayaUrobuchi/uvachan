#include <iostream>
using namespace std;

int main()
{
	int a, b;
	scanf("%d%d", &a, &b);
	int ans = max(a+b, max(a-b, a*b));
	printf("%d\n", ans);
	return 0;
}
