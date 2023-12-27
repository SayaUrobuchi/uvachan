#include <iostream>
#include <cmath>
using namespace std;
using ld = long double;

const double PI = acos(-1);

ld calc(ld r, ld h)
{
	r *= 1000;
	return acosl(r/(r+h));
}

int main()
{
	int count;
	ld r, a, b;
	scanf("%d", &count);
	while (count--)
	{
		scanf("%Lf%Lf%Lf", &r, &a, &b);
		printf("%.10Lf\n", (calc(r, a)+calc(r, b))*r);
	}
	return 0;
}