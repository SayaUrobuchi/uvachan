#include <stdio.h>
#include <math.h>

int main()
{
	long long n;
	while (scanf("%lld", &n) == 1)
	{
		printf("%.10lf\n", sqrt(n)*4);
	}
	return 0;
}
