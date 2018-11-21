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
			printf("�ռ�\n");
		}
		else if(sum < n)
		{
			printf("����\n");
		}
		else
		{
			printf("������\n");
		}
	}
	return 0;
}
