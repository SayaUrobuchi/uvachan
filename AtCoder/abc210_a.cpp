#include <iostream>
using namespace std;

int main()
{
	int n, m, a, b, c, d;
	while (scanf("%d%d%d%d", &n, &m, &a, &b) == 4)
	{
		c = min(n, m);
		d = max(n-m, 0);
		printf("%d\n", a*c+b*d);
	}
	return 0;
}
