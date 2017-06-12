#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char name[2008];

struct point
{
	int x, y, n;
};

struct point mass, p[1000], ch[1000];

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
	int n, m, i, j, ans;
	while(scanf("%s", name) == 1)
	{
		if(!strcmp(name, "#"))
		{
			break;
		}
		scanf("%d%d", &mass.x, &mass.y);
		n = 0;
		while(scanf("%d%d", &p[n].x, &p[n].y) == 2)
		{
			if(p[n].x == 0 && p[n].y == 0)
			{
				break;
			}
			n++;
			p[n-1].n = n;
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
		for(i=1, ans=1000000000; i<m; i++)
		{
			/*printf("%d %d\n", ch[i].n, ch[i-1].n);*/
			if(ch[i].n > ch[i-1].n)
			{
				if(ch[i].n < ans)
				{
					ans = ch[i].n;
				}
			}
			else
			{
				if(ch[i-1].n < ans)
				{
					ans = ch[i-1].n;
				}
			}
		}
		printf("%-20s%d\n", name, ans);
	}
	return 0;
}
