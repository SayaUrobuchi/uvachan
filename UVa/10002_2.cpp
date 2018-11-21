#include <stdio.h>
#include <stdlib.h>

double mx, my;

struct point
{
	int x, y;
};

struct point p[105], ch[305];

int comp(const void *p, const void *q)
{
	if(((struct point*)p)->x != ((struct point*)q)->x)
	{
		return ((struct point*)p)->x - ((struct point*)q)->x;
	}
	return ((struct point*)p)->y - ((struct point*)q)->y;
}

int cross(struct point p, struct point q, struct point r)
{
	return (q.x-p.x) * (r.y-p.y) - (q.y-p.y) * (r.x-p.x);
}

int main()
{
	int n, m, i, j;
	double weight, mass;
	while(scanf("%d", &n) == 1)
	{
		if(n < 3)
		{
			break;
		}
		for(i=0; i<n; i++)
		{
			scanf("%d%d", &p[i].x, &p[i].y);
		}
		qsort(p, n, sizeof(struct point), comp);
		for(i=0, m=0; i<n; i++)
		{
			for(; m>=2&&cross(ch[m-2], ch[m-1], p[i])<=0; m--);
			ch[m++] = p[i];
		}
		for(i=n-2, j=m+1; i>=0; i--)
		{
			for(; m>=j&&cross(ch[m-2], ch[m-1], p[i])<=0; m--);
			ch[m++] = p[i];
		}
		m--;
		for(i=2, weight=0.0; i<m; i++)
		{
			mass = cross(ch[0], ch[i-1], ch[i]);
			mx = mx*weight + ((ch[0].x + ch[i-1].x + ch[i].x) / 3.0) * mass;
			my = my*weight + ((ch[0].y + ch[i-1].y + ch[i].y) / 3.0) * mass;
			mx /= weight + mass;
			my /= weight + mass;
			weight += mass;
		}
		printf("%.3lf %.3lf\n", mx+1e-6, my+1e-6);
	}
	return 0;
}
