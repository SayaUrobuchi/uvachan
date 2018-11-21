#include <stdio.h>

struct point
{
	int x, y;
};

struct point p[55];

int cross(struct point p, struct point q, struct point r)
{
	return (q.x-p.x) * (r.y-p.y) - (q.y-p.y) * (r.x-p.x);
}

int main()
{
	int n, i, dir;
	while(scanf("%d", &n) == 1)
	{
		if(!n)
		{
			break;
		}
		for(i=0; i<n; i++)
		{
			scanf("%d%d", &p[i].x, &p[i].y);
		}
		p[n++] = p[0];
		p[n++] = p[1];
		for(i=3, dir=cross(p[0], p[1], p[2]); i<n; i++)
		{
			if(dir > 0)
			{
				if(cross(p[i-2], p[i-1], p[i]) < 0)
				{
					break;
				}
			}
			else
			{
				if(cross(p[i-2], p[i-1], p[i]) > 0)
				{
					break;
				}
			}
		}
		if(i == n)
		{
			printf("No\n");
		}
		else
		{
			printf("Yes\n");
		}
	}
	return 0;
}
