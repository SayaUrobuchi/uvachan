#include <stdio.h>

int main()
{
	int count, b;
	double p;
	scanf("%d", &count);
	while (count--)
	{
		scanf("%d%lf", &b, &p);
		printf("%.4lf %.4lf %.4lf\n", 60*(b-1)/p, 60*b/p, 60*(b+1)/p);
	}
	return 0;
}
