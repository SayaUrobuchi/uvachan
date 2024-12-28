#include <iostream>
using namespace std;

int main()
{
	int a, b, c, d, e, f;
	scanf("%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f);
	int ans = a + b + c + d + e + f
			- min(a, min(b, min(c, d))) - min(e, f);
	printf("%d\n", ans);
	return 0;
}
