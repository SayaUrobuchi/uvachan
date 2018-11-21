#include <stdio.h>

int main()
{
	int count;
	unsigned long long n, i, j, c, temp;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%llu", &n);
		for(i=0, j=1llu<<32; i<=j; )
		{
			c = ((i+j)>>1);
			if(c*(c+1) > 2*n)
			{
				j = c-1;
			}
			else
			{
				temp = c;
				i = c+1;
			}
		}
		printf("%llu\n", temp);
	}
	return 0;
}
