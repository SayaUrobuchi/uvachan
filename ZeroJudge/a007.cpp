#include <stdio.h>
#include <math.h>

int main()
{
	int n, sq, i;
	while(scanf("%d", &n) == 1)
	{
		if(n == 2)
		{
			printf("借计\n"); 
		}
		else if(!(n % 2))
		{
			printf("獶借计\n");
		}
		else
		{
			sq = sqrt(n) + 1;
			for(i=3; i<sq; i+=2)
			{
				if(!(n % i))
				{
					break;
				}
			}
			if(i < sq)
			{
				printf("獶借计\n");
			}
			else
			{
				printf("借计\n");
			}
		}
	}
	return 0;
}
