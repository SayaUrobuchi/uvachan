#include <stdio.h>

int gcd(int p, int q)
{
	return p % q ? gcd(q, p%q) : q;
}

int main()
{
	int i, j, x1, x2, y1, y2, z, xstep, ystep;
	while(scanf("%d", &z) == 1)
	{
		if(z == 0)
		{
			break;
		}
		scanf("%d%d%d%d", &x1, &x2, &y1, &y2);
		xstep = x2-x1, ystep=y2-y1;
		for(i=0; i<=ystep; i++)
		{
			for(j=0; j<=xstep; j++)
			{
				if(gcd(z, gcd(x1+j, y1+i)) == 1)
				{
					putchar('*');
				}
				else
				{
					putchar('.');
				}
			}
			putchar('\n');
		}
		puts("--");
	}
	return 0;
}
