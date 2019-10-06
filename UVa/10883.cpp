#include <stdio.h>
#include <math.h>
#include <iostream>
#include <iomanip>

const double IGNORE = -8;

double ary[65536];

int main()
{
	int cas, count, n, i, j, k, c, flag;
	double t, mon, est;
	double res, coe;
	cas = 0;
	scanf("%d", &count);
	while (count--)
	{
		scanf("%d", &n);
		mon = log10(2) * (n-1);
		est = log10(1);
		flag = 0;
		for (i=0; i<n; i++)
		{
			scanf("%lf", &ary[i]);
		}
		for (i=0, res=0; i<n; i++)
		{
			t = ary[i];
			if (est - mon > IGNORE)
			{
				if (!flag)
				{
					flag = 1;
					for (j=n-i, k=1, c=n-1, coe=1; k<=i; j++, k++)
					{
						coe = coe * j / k;
						while (c > 0 && coe > 10)
						{
							coe /= 2;
							c--;
						}
					}
					while (c > 0)
					{
						coe /= 2;
						c--;
					}
				}
				else
				{
					coe = coe * (n-i) / i;
				}
				res += coe * t;
			}
			else if (flag)
			{
				break;
			}
			est += log10(n-i-1) - log10(i+1);
		}
		printf("Case #%d: %.3lf\n", ++cas, res);
	}
	return 0;
}
