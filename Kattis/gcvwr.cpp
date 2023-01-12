#include <iostream>
using namespace std;

int main()
{
	int n, a, b, c, i, t;
	scanf("%d%d%d", &a, &b, &n);
	c = a - b;
	c = (c/10) * 9;
	for (i=0; i<n; i++)
	{
		scanf("%d", &t);
		c -= t;
	}
	printf("%d\n", c);
	return 0;
}