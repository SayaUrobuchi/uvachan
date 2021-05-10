#include <iostream>

int main()
{
	int n, m, a, b;
	double c;
	while (scanf("%d%d%d%d", &n, &m, &a, &b) == 4)
	{
		a *= n;
		b *= m;
		c = (a-b) * 1.0 / (n-m);
		if (c < 0 || c > 100)
		{
			puts("impossible");
		}
		else
		{
			printf("%.10lf\n", c);
		}
	}
	return 0;
}