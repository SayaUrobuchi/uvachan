#include <iostream>

const double AREA = 250*125;
const double N = 250.0;

int main()
{
	int x, y;
	double ax, ay;
	while (scanf("%d%d", &x, &y) == 2)
	{
		if (x == 0)
		{
			if (y > 125)
			{
				ay = 0;
				ax = AREA/y;
			}
			else
			{
				ax = AREA/(N-y);
				ay = N - ax;
			}
		}
		else if (y == 0)
		{
			if (x > 125)
			{
				ax = 0;
				ay = AREA/x;
			}
			else
			{
				ay = AREA/(N-x);
				ax = N - ay;
			}
		}
		else
		{
			if (x+x < N)
			{
				ay = 0;
				ax = N-AREA/y;
			}
			else
			{
				ax = 0;
				ay = N-AREA/x;
			}
		}
		printf("%.2lf %.2lf\n", ax, ay);
	}
	return 0;
}
