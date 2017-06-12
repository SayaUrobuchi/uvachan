#include <stdio.h>

int calc(int a, int b)
{
	int r, t, tt;
	r = 0;
	t = 1;
	tt = a;
	while(a > 0)
	{
		if(a % 10 > b)
		{
			r += (a/10+!!b)*t;
		}
		else if(a % 10 < b)
		{
			r += a/10*t;
		}
		else
		{
			r += a/10*t+(tt%t+1);
		}
		a /= 10;
		t *= 10;
	}
	return r;
}

int main()
{
	int count, n, i;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d", &n);
		for(i=0; i<=9; i++)
		{
			if(i)
			{
				printf(" ");
			}
			printf("%d", calc(n, i));
		}
		printf("\n");
	}
	return 0;
}
