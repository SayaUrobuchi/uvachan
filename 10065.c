#include <stdio.h>
#include <stdlib.h>

int x[105], y[105], p[105], s[210];

int comp(const void *p, const void *q)
{
	int a, b;
	a = *(int*)p;
	b = *(int*)q;
	return x[a]==x[b] ? y[a]-y[b] : x[a]-x[b];
}

int cross(int x1, int y1, int x2, int y2)
{
	return x1*y2 - x2*y1;
}

int main()
{
	int cas, n, i, m, t;
	double area, carea;
	cas = 0;
	while(scanf("%d", &n) == 1)
	{
		if(n == 0)
		{
			break;
		}
		for(i=0, area=0; i<n; i++)
		{
			scanf("%d%d", &x[i], &y[i]);
			if(i)
			{
				area += x[i-1]*y[i] - x[i]*y[i-1];
			}
			p[i] = i;
		}
		area += x[n-1]*y[0] - x[0]*y[n-1];
		area /= 2;
		if(area < 0)
		{
			area = -area;
		}
		qsort(p, n, sizeof(int), comp);
		for(i=0, m=0; i<n; i++)
		{
			while(m>=2&&cross(x[p[i]]-x[s[m-2]], y[p[i]]-y[s[m-2]], x[p[i]]-x[s[m-1]], y[p[i]]-y[s[m-1]])<=0)
			{
				m--;
			}
			s[m++] = p[i];
		}
		for(i=n-2, t=m; i>=0; i--)
		{
			while(m>t&&cross(x[p[i]]-x[s[m-2]], y[p[i]]-y[s[m-2]], x[p[i]]-x[s[m-1]], y[p[i]]-y[s[m-1]])<=0)
			{
				m--;
			}
			s[m++] = p[i];
		}
		for(i=1, carea=0; i<m; i++)
		{
			carea += x[s[i-1]]*y[s[i]] - x[s[i]]*y[s[i-1]];
		}
		carea /= 2;
		if(carea < 0)
		{
			carea = -carea;
		}
		printf("Tile #%d\nWasted Space = %.2lf %%\n\n", ++cas, 100.0*(carea-area)/carea);
	}
	return 0;
}

