#include <stdio.h>
#include <math.h>

const double PI = acos(-1);

int px[16384], py[16384];

double getdis(int x, int y)
{
	return sqrt(x*x+y*y);
}

int main()
{
	int count, n, m, i;
	double len, r;
	scanf("%d", &count);
	while (count--)
	{
		scanf("%d%d", &m, &n);
		for (i=0, len=0; i<n; i++)
		{
			scanf("%d%d", &px[i], &py[i]);
			if (i)
			{
				len += getdis(px[i]-px[i-1], py[i]-py[i-1]);
			}
		}
		len += getdis(px[0]-px[n-1], py[0]-py[n-1]);
		r = 2*PI*m;
		if (r >= len)
		{
			puts("Not possible");
		}
		else
		{
			printf("%.10lf\n", 1.0-2*PI*m/len);
		}
	}
	return 0;
}
