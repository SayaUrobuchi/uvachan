#include <stdio.h>

int main()
{
	int n, i, sum;
	while(scanf("%d", &n) == 1)
	{
		if(n == 0)
		{
			break;
		}
		for(i=1, sum=0; i<=n; i+=2)
		{
			if(n % i == 0)
			{
				sum += i;
			}
		}
		sum *= 8 * (!(n%2)*2+1);
		printf("%d\n", sum);
	}
	return 0;
}
