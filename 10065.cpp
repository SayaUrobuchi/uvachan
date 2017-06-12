#include <stdio.h>
#include <stdlib.h>

struct point
{
	int x, y;
};

struct point p[105], ch[205];

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
	int cas, n, m, i, j, area, carea, temp;
	cas = 0;
	while(scanf("%d", &n) == 1)
	{
		for(i=0; i<n; i++)
		{
			scanf("%d%d", &p[i].x, &p[i].y);
		}
		qsort(p, n, sizeof(struct point), comp);
		for(i=0, area=0, m=0; i<n; i++)
		{
			for(; m>=2&&(temp=cross(ch[m-2], ch[m-1], p[i]))<=0; area+=abs(temp), m--);
			ch[m++] = p[i];
		}
		for(i=n-2, j=m+1; i>=0; i--)
		{
			for(; m>=j&&(temp=cross(ch[m-2], ch[m-1], p[i]))<=0; area+=abs(temp), m--);
			ch[m++] = p[i];
		}
		printf("%d\n", m);
		for(i=2, m--, carea=0; i<m; i++)
		{
			carea += abs(cross(ch[0], ch[i-1], ch[i]));
		}
		printf("Tile #%d\n", ++cas);
		printf("Wasted Space = %.2lf %%\n\n", (100.0*area)/carea);
	}
	return 0;
}
