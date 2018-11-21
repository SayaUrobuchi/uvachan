#include <stdio.h>
#include <math.h>

int ary[10001];

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
		temp = n - 1;
		if(n == 3)
		{
			printf("3 coconuts, 2 people and 1 monkey\n");
			continue;
		}
		for(i=2+temp%2, s=1+temp%2, sq=(int)sqrt((double)temp)+1, j=0; i<sq; i+=s)
		{
			if(!(temp % i))
			{
				ary[j++] = i;
				if(deal(n, temp/i, 0))
				{
					break;
				}
			}
		}
		if(i < sq)
		{
			printf("%d coconuts, %d people and 1 monkey\n", n, temp/i);
		}
		else
		{
			for(i=j-1; i>=0; i--)
			{
				if(deal(n, ary[i], 0))
				{
					break;
				}
			}
			if(i >= 0)
			{
				printf("%d coconuts, %d people and 1 monkey\n", n, ary[i]);
			}
			else
			{
				printf("%d coconuts, no solution\n", n);
			}
		}
	}
	return 0;
}
