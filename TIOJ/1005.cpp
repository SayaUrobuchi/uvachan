#include <stdio.h>
#include <math.h>

int ary[50];

int gcd(int p, int q)
{
	if(p % q)
	{
		return gcd(q, p%q);
	}
	return q;
}

int main()
{
	int n, i, j, k, l;
	while(scanf("%d", &n) == 1)
	{
		if(!n)
		{
			break;
		}
		for(i=0, k=0, l=0; i<n; i++)
		{
			scanf("%d", &ary[i]);
			for(j=0; j<i; j++, k++)
			{
				l += (gcd(ary[i], ary[j]) == 1);
			}
		}
		if(!l)
		{
			printf("No estimate for this data set.\n");
		}
		else
		{
			k *= 6;
			printf("%.6f\n", sqrt((double)k / l));
		}
	}
	return 0;
}
