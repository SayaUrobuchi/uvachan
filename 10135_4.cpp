#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define INF 1e30

struct point
{
	double x, y;
};

struct point p[1005], ch[3005], o;

int comp(const void *p, const void *q)
{
	struct point *a = (struct point*)p, *b = (struct point*)q;
	return atan2(a->x, a->y) > atan2(b->x, b->y) ? 1 : -1;
}

double getdist(double x, double y)
{
	return sqrt(x*x+y*y);
}

double cross(struct point p, struct point q, struct point r)
{
	return (q.x-p.x) * (r.y-p.y) - (q.y-r.y) * (r.x-p.x);
}

int main()
{
	int count, n, m, i, j, k;
	double len, ml, ans, tl, ul;
	o.x = o.y = 0;
	/* freopen("1.txt", "w", stdout); */
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d", &n);
		for(i=0; i<n; i++)
		{
			scanf("%lf%lf", &p[i].x, &p[i].y);
		}
		p[n++] = o;
		qsort(p, n, sizeof(struct point), comp);
		/* try every point directly connected to o */
		ans = -1;
		for(i=1, len=2.0; i<n; i++)
		{
			len += getdist(p[i-1].x-p[i].x, p[i-1].y-p[i].y);
		}
		len += getdist(p[0].x-p[n-1].x, p[0].y-p[n-1].y);
		ml = getdist(p[0].x, p[0].y)+getdist(p[n-1].x, p[n-1].y)-getdist(p[0].x-p[n-1].x, p[0].y-p[n-1].y);
		for (k=1; k<n; k++)
		{
			tl = getdist(p[k].x, p[k].y)+getdist(p[k-1].x, p[k-1].y)-getdist(p[k].x-p[k-1].x, p[k].y-p[k-1].y);
			if (tl < ml)
			{
				ml = tl;
			}
		}
		printf("%.2lf\n", len+ml);
		if(count)
		{
			printf("\n");
		}
	}
	return 0;
}
