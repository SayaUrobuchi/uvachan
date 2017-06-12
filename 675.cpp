#include <stdio.h>
#include <stdlib.h>

#define N 10005

struct point
{
	int x, y;
};

struct point p[N], ch[N];

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
	n = 0;
	while(scanf("%d, %d", &p[n].x, &p[n].y) == 2)
	{
		n++;
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
	for(i=0; i<m; i++)
	{
		printf("%d, %d\n", ch[i]);
	}
	/*for(; ; );*/
	return 0;
}
