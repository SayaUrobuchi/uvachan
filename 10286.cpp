#include <stdio.h>
#include <math.h>

int main()
{
    double f, pi, sin63, sin108;
    pi = 2.0 * acos(0.0);
    sin63 = sin(63 * pi / 180);
    sin108 = sin(108 * pi / 180);
    while(scanf("%lf", &f) == 1)
    {
		f /= sin63;
		f *= sin108;
		printf("%.10f\n", f);
    }
    return 0;
}