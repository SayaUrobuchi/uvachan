#include <stdio.h>

int main()
{
	int n;
	while(scanf("%d", &n) == 1)
	{
		printf("%.3lf\n", (n-32)*5.0/9.0);
	}
	return 0;
}
