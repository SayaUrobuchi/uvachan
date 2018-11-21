#include <stdio.h>

int deal(int now, int div, int depth)
{
	/*printf("%d %d %d\n", now, div, depth);*/
	if(depth == div)
	{
		return !(now % div);
	}
	if(now % div == 1)
	{
		return deal((now/div)*(div-1), div, depth+1);
	}
	return 0;
}

int main()
{
	int n, i, j, s, temp, sq;
	while(scanf("%d", &n) == 1)
	{
		if(n < 0)
		{
			break;
		}
		if(n > 2)
		{
			temp = n - 1;
			for(i=9; i>=2; i--)
			{
				if(!(temp % i))
				{
					if(deal(n, i, 0))
					{
						break;
					}
				}
			}
		}
		else
		{
			i = 0;
		}
		if(i >= 2)
		{
			printf("%d coconuts, %d people and 1 monkey\n", n, i);
		}
		else
		{
			printf("%d coconuts, no solution\n", n);
		}
	}
	return 0;
}
