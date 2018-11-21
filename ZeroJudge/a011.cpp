#include <stdio.h>

int main()
{
	unsigned long long a, b;
	while(scanf("%llu%llu", &a, &b) == 2)
	{
		if(a > b)
		{
			printf("%llu\n", a-b);
		}
		else
		{
			printf("%llu\n", b-a);
		}
	}
	return 0;
}
