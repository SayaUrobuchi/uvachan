#include <iostream>
using namespace std;

int main()
{
	int a, b, c, d;
	scanf("%d%d%d%d", &a, &b, &c, &d);
	int ans = min(a, min(b, min(c, d)));
	printf("%d\n", ans);
	return 0;
}
