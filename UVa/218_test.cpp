#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct __point
{
	double x, y;
}point;

int n;
point ary[1000005];
point ch[1000005];

double getdist(double x, double y)
{
	return sqrt(x*x+y*y);
}

int p_comp(const void *p, const void *q)
{
	if(((point*)p)->x != ((point*)q)->x)
	{
		return ((point*)p)->x > ((point*)q)->x ? 1 : -1;
	}
	return ((point*)p)->y > ((point*)q)->y ? 1 : -1;
}

double cross(point &p, point &q, point &r)
{
	return (q.x-p.x) * (r.y-p.y) - (q.y-p.y) * (r.x-p.x);
}

void convex_hull(point *ch, int *c_num)
{
	int m, i, j;
	qsort(ary, n, sizeof(point), p_comp);
	for(i=0, m=0; i<n; i++)
	{
		for(; m>=2&&cross(ch[m-2], ch[m-1], ary[i])<=0; m--);
		ch[m++] = ary[i];
	}
	for(i=n-2, j=m+1; i>=0; i--)
	{
		for(; m>=j&&cross(ch[m-2], ch[m-1], ary[i])<=0; m--);
		ch[m++] = ary[i];
	}
	*c_num = m;
}

int main()
{
	int cas, m, i, j;
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
			scanf("%lf%lf", &ary[i].x, &ary[i].y);
		}
		convex_hull(ch, &m);
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
