#include <stdio.h>

int main()
{
	int n, c, i, j;
	while(scanf("%d", &n) == 1)
	{
		if(n == 0)
		{
			break;
		}
		c = 0;
		for(i=n, j=1; i>0; i/=10, j*=9)
		{
			c += (i/10) * j + (i%10 >= 4) * j;
		}
		printf("%d: %d\n", n, n-c);
	}
	return 0;
}
