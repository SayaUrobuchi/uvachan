#include <stdio.h>

int aryx[10005], aryy[10005];

int ab(int now)
{
	return now < 0 ? -now : now;
}

int main()
{
	int n, m, i, j, k, x, y, base, upstep, downstep;
	for(i=1, x=0, base=5, upstep=4, downstep=7; i<=10000; i+=base, base+=6, upstep+=6, downstep+=6, x++)
	{
		for(j=i+upstep, k=upstep+6, y=-x-2; j<=10000; j+=k, k+=6, y-=2)
		{
			aryx[j] = x;
			aryy[j] = y;
		}
		for(j=i, k=0, y=-x; j<=10000&&k<=x; j++, k++, y+=2)
		{
			aryx[j] = x;
			aryy[j] = y;
		}
		for(k=downstep; j<=10000; j+=k, k+=6, y+=2)
		{
			aryx[j] = x;
			aryy[j] = y;
		}
	}
	for(i=4, x=-1, base=9, upstep=10, downstep=7; i+x<=10000; i+=base, base+=6, upstep+=6, downstep+=6, x--)
	{
		for(j=i+upstep, k=upstep+6, y=x-2; j<=10000; j+=k, k+=6, y-=2)
		{
			aryx[j] = x;
			aryy[j] = y;
		}
		for(j=i, k=0, y=x; k>=x; j--, k--, y+=2)
		{
			if(j <= 10000)
			{
				aryx[j] = x;
				aryy[j] = y;
			}
		}
		for(j+=downstep+1, k=downstep+6; j<=10000; j+=k, k+=6, y+=2)
		{
			aryx[j] = x;
			aryy[j] = y;
		}
	}
	while(scanf("%d%d", &n, &m) == 2)
	{
		if(n == 0 && m == 0)
		{
			break;
		}
		/*printf("n: x %d, y %d.\n", aryx[n], aryy[n]);
		printf("m: x %d, y %d.\n", aryx[m], aryy[m]);*/
		printf("The distance between cells %d and %d is %d.\n", n, m, ab(aryx[n]-aryx[m])+((k=ab(aryy[n]-aryy[m])-ab(aryx[n]-aryx[m]))>0?k/2:0));
	}
	return 0;
}
