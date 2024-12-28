#include <iostream>
using namespace std;

int main()
{
	int a, b, c, d, e;
	scanf("%d%d%d%d%d", &a, &b, &c, &d, &e);
	int ans = max(0, min(a, min(b, c)) + min(d, e) - 50);
	printf("%d\n", ans);
	return 0;
}
