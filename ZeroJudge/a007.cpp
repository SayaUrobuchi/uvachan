#include <stdio.h>
#include <math.h>

int main()
{
	int n, sq, i;
	while(scanf("%d", &n) == 1)
	{
		if(n == 2)
		{
			printf("���\n"); 
		}
		else if(!(n % 2))
		{
			printf("�D���\n");
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
				printf("�D���\n");
			}
			else
			{
				printf("���\n");
			}
		}
	}
	return 0;
}
