#include <stdio.h>
#include <math.h>

int stack[2000], n;

int main()
{
	int cas, count, c, r, i, m, s, lim;
	cas = 0;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d%d", &c, &r);
		c -= r;
		if(c)
		{
			if(c <= r)
			{
				printf("Case #%d:\n", ++cas);
			}
			else
			{
				if(r)
				{
					printf("Case #%d:", ++cas);
				}
				else
				{
					printf("Case #%d: 1", ++cas);
				}
				stack[0] = c;
				n = 1;
				for(m=c%2, i=2+m, s=1+m, lim=sqrt(c)+1; i<lim; i+=s)
				{
					if(!(c % i))
					{
						stack[n++] = c / i;
						if(i > r)
						{
							printf(" %d", i);
						}
					}
				}
				for(i=n-1; i>-1; i--)
				{
					if(stack[i] > r)
					{
						break;
					}
				}
				if(i > -1 && stack[i] * stack[i] == c)
				{
					i--;
				}
				for(; i>-1; i--)
				{
					printf(" %d", stack[i]);
				}
				printf("\n");
			}
		}
		else
		{
			printf("Case #%d: 0\n", ++cas);
		}
	}
	return 0;
}
