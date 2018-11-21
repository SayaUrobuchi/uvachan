#include <stdio.h>
#include <stdlib.h>

struct point
{
	int x, y;
};

struct point p[600], ch[600];

int comp(const void *p, const void *q)
{
	if(((struct point*)p)->y != ((struct point*)q)->y)
	{
		return ((struct point*)p)->y - ((struct point*)q)->y;
	}
	return ((struct point*)p)->x - ((struct point*)q)->x;
}

int cross(struct point p, struct point q, struct point r)
{
	return (q.x-p.x) * (r.y-p.y) - (q.y-p.y) * (r.x-p.x);
}

int main()
{
	int count, n, m, i, j;
	scanf("%d", &count);
	printf("%d\n", count);
	while(count--)
	{
		scanf("%d", &n);
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
		printf("%d\n", m);
		for(i=0; i<m; i++)
		{
			printf("%d %d\n", ch[i].x, ch[i].y);
		}
		if(count)
		{
			scanf("%*d");
			printf("-1\n");
		}
	}
	return 0;
}
