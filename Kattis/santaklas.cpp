#include <iostream>
#include <cmath>

const double PI = acos(-1);

int main()
{
	int h, a;
	double v;
	while (scanf("%d%d", &h, &a) == 2)
	{
		v = sin(a*PI/180);
		if (v < 0)
		{
			printf("%d\n", (int)(h/-v));
		}
		else
		{
			puts("safe");
		}
	}
	return 0;
}
