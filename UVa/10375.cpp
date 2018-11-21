#include <stdio.h>
#include <stdlib.h>

int comp(const void *p, const void *q)
{
	return *(int*)p - *(int*)q;
}

int main()
{
	int p, q, r, s, i, j, ex, a[3], b[3];
	double ans;
	while(scanf("%d%d%d%d", &p, &q, &r, &s) == 4)
	{
		a[0] = p;
		a[1] = s;
		a[2] = r-s;
		b[0] = r;
		b[1] = q;
		b[2] = p-q;
		qsort(a, 3, sizeof(int), comp);
		qsort(b, 3, sizeof(int), comp);
		ans = 1;
		for(i=0, ex=0; i<3; i++)
		{
			if(a[i] > b[i])
			{
				for(j=b[i]+1; j<=a[i]; j++)
				{
					ans *= j;
					while(ans >= 10.0)
					{
						ans /= 10.0;
						ex++;
					}
				}
			}
			else
			{
				for(j=a[i]+1; j<=b[i]; j++)
				{
					ans /= j;
					while(ans < 1.0)
					{
						ans *= 10.0;
						ex--;
					}
				}
			}
		}
		if(ex > 0)
		{
			for(i=0; i<ex; i++)
			{
				ans *= 10;
			}
		}
		else
		{
			for(i=0; i>ex; i--)
			{
				ans /= 10;
			}
		}
		printf("%.5f\n", ans+0.00000003);
	}
	return 0;
}
