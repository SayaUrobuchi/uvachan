#include <stdio.h>
#include <stdlib.h>

struct point
{
	int x, y;
};

struct point cop[205], robber[205], cch[205], rch[205], c;

int comp(const void *p, const void *q)
{
	if(((struct point*)p)->x != ((struct point*)q)->x)
	{
		return ((struct point*)p)->x - ((struct point*)q)->x;
	}
	return ((struct point*)p)->y - ((struct point*)q)->y;
}

int max(int p, int q)
{
	if(p > q)
	{
		return p;
	}
	return q;
}

int min(int p, int q)
{
	if(p < q)
	{
		return p;
	}
	return q;
}

int cross(struct point p, struct point q, struct point r)
{
	return (q.x-p.x) * (r.y-p.y) - (q.y-p.y) * (r.x-p.x);
}

int check(struct point p, struct point q, struct point r)
{
	return r.x > max(p.x, q.x) || r.x < min(p.x, q.x) || r.y > max(p.y, q.y) || r.y < min(p.y, q.y);
}

int main()
{
	int cas, n, m, o, i, j, cm, rm;
	cas = 0;
	while(scanf("%d%d%d", &n, &m, &o) == 3)
	{
		if(!n && !m && !o)
		{
			break;
		}
		for(i=0; i<n; i++)
		{
			scanf("%d%d", &cop[i].x, &cop[i].y);
		}
		if(n >= 3)
		{
			qsort(cop, n, sizeof(struct point), comp);
			for(i=0, cm=0; i<n; i++)
			{
				for(; cm>=2&&cross(cch[cm-2], cch[cm-1], cop[i])<=0; cm--);
				cch[cm++] = cop[i];
			}
			for(i=n-2, j=cm+1; i>=0; i--)
			{
				for(; cm>=j&&cross(cch[cm-2], cch[cm-1], cop[i])<=0; cm--);
				cch[cm++] = cop[i];
			}
		}
		/*printf("CONVEX HULL START\n");
		for(i=0; i<cm; i++)
		{
			printf("%d %d\n", cch[i].x, cch[i].y);
		}
		printf("FINISH!\n");*/
		for(i=0; i<m; i++)
		{
			scanf("%d%d", &robber[i].x, &robber[i].y);
		}
		if(m >= 3)
		{
			qsort(robber, m, sizeof(struct point), comp);
			for(i=0, rm=0; i<m; i++)
			{
				for(; rm>=2&&cross(rch[rm-2], rch[rm-1], robber[i])<=0; rm--);
				rch[rm++] = robber[i];
			}
			for(i=m-2, j=rm+1; i>=0; i--)
			{
				for(; rm>=j&&cross(rch[rm-2], rch[rm-1], robber[i])<=0; rm--);
				rch[rm++] = robber[i];
			}
		}
		printf("Data set %d:\n", ++cas);
		while(o--)
		{
			scanf("%d%d", &c.x, &c.y);
			if(n >= 3)
			{
				for(i=1; i<cm; i++)
				{
					if(cross(cch[i-1], cch[i], c) < 0 || (cross(cch[i-1], cch[i], c) == 0 && check(cch[i-1], cch[i], c)))
					{
						break;
					}
				}
				if(i == cm)
				{
					printf("     Citizen at (%d,%d) is safe.\n", c.x, c.y);
					continue;
				}
			}
			if(m >= 3)
			{
				for(i=1; i<rm; i++)
				{
					if(cross(rch[i-1], rch[i], c) < 0 || (cross(rch[i-1], rch[i], c) == 0 && check(rch[i-1], rch[i], c)))
					{
						break;
					}
				}
				if(i == rm)
				{
					printf("     Citizen at (%d,%d) is robbed.\n", c.x, c.y);
					continue;
				}
			}
			printf("     Citizen at (%d,%d) is neither.\n", c.x, c.y);
		}
		printf("\n");
	}
	return 0;
}
