#include <stdio.h>

int gcd(int &a, int &b)
{
	int x, y, d;
	y = a % b;
	if(y)
	{
		x = b;
		d = gcd(x, y);
		b = x - a / b * y;
		a = y;
	}
	else
	{
		d = b;
		a = 0;
		b = 1;
	}
	return d;
}

int main()
{
	int a, b, d;
	while(scanf("%d%d", &a, &b) == 2)
	{
		d = gcd(a, b);
		printf("%d %d %d\n", a, b, d);
	}
	return 0;
}