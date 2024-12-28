#include <iostream>
using namespace std;

int main()
{
	int a, b, c, d, p;
	scanf("%d%d%d%d%d", &a, &b, &c, &d, &p);
	int ans = min(a*p, max(0, (p-c)*d)+b);
	printf("%d\n", ans);
	return 0;
}
