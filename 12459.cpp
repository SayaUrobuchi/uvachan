#include <stdio.h>

long long fib[85];

int main()
{
	int i;
	fib[0] = 1;
	fib[1] = 1;
	for(i=2; i<=80; i++)
	{
		fib[i] = fib[i-1]+fib[i-2];
	}
	while(scanf("%d", &i) == 1)
	{
		if(i == 0)
		{
			break;
		}
		printf("%lld\n", fib[i]);
	}
	return 0;
}
