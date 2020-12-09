#include <iostream>
#include <cmath>

int main()
{
	double a, b;
	while (scanf("%lf%lf", &a, &b) == 2)
	{
		//printf("square %.10lf\n", sqrt(a)*4);
		//printf("circle %.10lf\n", sqrt(a/acos(-1))*2*acos(-1));
		puts((sqrt(a/acos(-1))*2*acos(-1) <= b) ? "Diablo is happy!" : "Need more materials!");
	}
	return 0;
}
