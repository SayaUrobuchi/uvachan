#include <stdio.h>

int main()
{
	int a, b;
	while (scanf("%d%d", &a, &b) == 2)
	{
		printf("%.10lf\n", ((a-b)*(a-b))*100./(a*a));
	}
	return 0;
}
