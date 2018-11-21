#include <stdio.h>
#include <math.h>

int main()
{
	int n, i, sq, sum;
	while(scanf("%d", &n) == 1)
	{
		for(i=2, sq=sqrt(n)+1, sum=1; i<sq; i++)
		{
			if(n % i == 0)
			{
				sum += n/i;
				if(n/i != i)
				{
					sum += i;
				}
				if(sum > n)
				{
					break;
				}
			}
		}
		if(sum > n)
		{
			printf("盈數\n");
		}
		else if(sum < n)
		{
			printf("虧數\n");
		}
		else
		{
			printf("完全數\n");
		}
	}
	return 0;
}
