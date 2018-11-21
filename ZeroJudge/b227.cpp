#include <stdio.h>

int main()
{
	int count, n, m, a, b;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d%d", &n, &m);
		a = (m*(n-(n&1)))*800+(n&1)*m*1000;
		b = (n*m)*812;
		if(a % 1000)
		{
			a = a+1000-a%1000;
		}
		if(b % 1000)
		{
			b = b+1000-b%1000;
		}
		if(a < b)
		{
			printf(": )\n");
		}
		else if(a > b)
		{
			printf("8-12=-4\n");
		}
		else
		{
			printf("SAME\n");
		}
	}
	return 0;
}
