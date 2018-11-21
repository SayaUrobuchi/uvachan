#include <stdio.h>
#include <math.h>

char s1[2], s2[2];

int main()
{
	double n, m, t, h, d, temp;
	while(scanf("%s", s1) == 1)
	{
		if(s1[0] == 'E')
		{
			break;
		}
		scanf("%lf%s%lf", &n, s2, &m);
		if(s1[0] > s2[0])
		{
			s1[0] ^= s2[0] ^= s1[0] ^= s2[0];
			temp = n;
			n = m;
			m = temp;
		}
		if(s1[0] == 'D' && s2[0] == 'H')
		{
			t = m - (0.5555) * (6.11 * exp(5417.7530 * (1/273.16 - 1/(n+273.16))) - 10.0);
			printf("T %.1f D %.1f H %.1f\n", t, n, m);
		}
		else if(s1[0] == 'D' && s2[0] == 'T')
		{
			h = m + (0.5555) * (6.11 * exp(5417.7530 * (1/273.16 - 1/(n+273.16))) - 10.0);
			printf("T %.1f D %.1f H %.1f\n", m, n, h);
		}
		else
		{
			d = 1.0/(-(log(((n-m)/0.5555 + 10.0) / 6.11) / 5417.7530 - 1/273.16)) - 273.16;
			printf("T %.1f D %.1f H %.1f\n", m, d, n);
		}
	}
	return 0;
}
