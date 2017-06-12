#include <stdio.h>
#include <math.h>

int main()
{
	int a, b, c;
	double sum, triangle, circle, circle2, pi;
	pi = 2.0 * acos(0.0);
	while(scanf("%d%d%d", &a, &b, &c) == 3)
	{
		sum = a + b + c;
		sum /= 2;
		triangle = sum * (sum - a) * (sum - b) * (sum - c);
		triangle = sqrt(triangle);
		circle = triangle / sum;
		circle2 = circle * c / 2;
		circle *= circle;
		circle *= pi;
		circle2 *= circle2;
		circle2 *= pi;
		printf("%.4f %.4f %.4f\n", circle2 - triangle, triangle - circle, circle);
	}
	return 0;
}
