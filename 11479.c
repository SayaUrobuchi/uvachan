#include <stdio.h>

int main()
{
	int cas, count, a, b, c, t;
	cas = 0;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d%d%d", &a, &b, &c);
		if(a > b)
		{
			t = a;
			a = b;
			b = t;
		}
		if(a > c)
		{
			t = a;
			a = c;
			c = t;
		}
		if(b > c)
		{
			t = b;
			b = c;
			c = t;
		}
		if(a < 0 || c-a >= b)
		{
			printf("Case %d: Invalid\n", ++cas);
		}
		else
		{
			t = (a == b) + (b == c);
			if(t == 2)
			{
				printf("Case %d: Equilateral\n", ++cas);
			}
			else if(t == 1)
			{
				printf("Case %d: Isosceles\n", ++cas);
			}
			else
			{
				printf("Case %d: Scalene\n", ++cas);
			}
		}
	}
	return 0;
}

