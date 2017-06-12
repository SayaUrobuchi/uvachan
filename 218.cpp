#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct point
{
	double x, y;
};

struct point p[1000], ch[1000];

int comp(const void *p, const void *q)
{
	double x1, x2, y1, y2;
	x1 = ((struct point*)p)->x;
	x2 = ((struct point*)q)->x;
	y1 = ((struct point*)p)->y;
	y2 = ((struct point*)q)->y;
	if(x1 != x2)
	{
		if(x1 > x2)
		{
			return 1;
		}
		return -1;
	}
	if(y1 > y2)
	{
		return 1;
	}
	else if(y1 == y2)
	{
		return 0;
	}
	return -1;
}

double getdist(double x, double y)
{
	return sqrt(x*x+y*y);
}

double cross(struct point p, struct point q, struct point r)
{
	return (q.x-p.x) * (r.y-p.y) - (q.y-p.y) * (r.x-p.x);
}

int main()
{
	int cas, n, m, i, j;
	double ans;
	cas = 0;
	while(scanf("%d", &n) == 1)
	{
		if(!n)
		{
			break;
		}
		for(i=0; i<n; i++)
		{
			scanf("%lf%lf", &p[i].x, &p[i].y);
		}
		qsort(p, n, sizeof(struct point), comp);
		for(i=0, m=0; i<n; i++)
		{
			for(; m>=2&&cross(ch[m-2], ch[m-1], p[i])>=0; m--);
			ch[m++] = p[i];
		}
		for(i=n-2, j=m+1; i>=0; i--)
		{
			for(; m>=j&&cross(ch[m-2], ch[m-1], p[i])>=0; m--);
			ch[m++] = p[i];
		}
		if(cas)
		{
			printf("\n");
		}
		printf("Region #%d:\n", ++cas);
		printf("(%.1lf,%.1lf)", ch[0].x, ch[0].y);
		for(i=1, ans=0.0; i<m; i++)
		{
			printf("-(%.1lf,%.1lf)", ch[i].x, ch[i].y);
			ans += getdist(ch[i-1].x-ch[i].x, ch[i-1].y-ch[i].y);
		}
		printf("\n");
		printf("Perimeter length = %.2lf\n", ans);
	}
	return 0;
}
