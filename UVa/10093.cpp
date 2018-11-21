#include <stdio.h>

int main()
{
	int n, i, j, max, sum;
	char buf[100001];
	while(gets(buf))
	{
		n = 0;
		if(buf[0] == '+' || buf[0] == '-')
		{
			n = 1;
		}
		max = 1;
		sum = 0;
		for(; buf[n]; n++)
		{
			if(buf[n] > 90)
			{
				buf[n] -= 61;
			}
			else if(buf[n] > 58)
			{
				buf[n] -= 55;
			}
			else
			{
				buf[n] -= 48;
			}
			if(buf[n] > max)
			{
				max = buf[n];
			}
			sum += buf[n];
		}
		for(i=max+1; i<63; i++)
		{
			if(!(sum % (i-1)))
			{
				printf("%d\n", i);
				break;
			}
		}
		if(i == 63)
		{
			printf("such number is impossible!\n");
		}
	}
	return 0;
}
