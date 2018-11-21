#include <stdio.h>

int main()
{
	int n, m;
	while(scanf("%d%d", &n, &m) == 2)
	{
		if(n > m)
		{
			n ^= m ^= n ^= m;
		}
		if(m % n)
		{
			printf("N\n");
		}
		else
		{
			printf("Y\n");
		}
	}
	return 0;
}
