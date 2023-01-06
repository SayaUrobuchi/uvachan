#include <iostream>
using namespace std;

int main()
{
	int a, b, c, d, u, v;
	scanf("%d%d%d%d", &a, &b, &c, &d);
	u = max(a, c);
	v = min(b, d);
	printf("%d\n", max(0, v-u));
	return 0;
}
