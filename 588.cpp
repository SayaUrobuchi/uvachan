#include <stdio.h>

#define INF 1000000000

int n, lx, ly, rx, ry, bx1, bx2, by1, by2;
int px[101], py[101];

int min(int p, int q)
{
	if(p < q)
	{
		return p;
	}
	return q;
}

int max(int p, int q)
{
	if(p > q)
	{
		return p;
	}
	return q;
}

int getrect(int x1, int y1, int x2, int y2)
{
	int i, minx, maxx, miny, maxy, minr, maxr;
	minx = min(x1, x2);
	maxx = max(x1, x2);
	miny = min(y1, y2);
	maxy = max(y1, y2);
	if(x1 == x2)
	{
		for(i=1, maxr=-INF, minr=INF; i<n; i++)
		{
			if(px[i] == px[i-1] && miny < max(py[i], py[i-1]) && maxy > min(py[i], py[i-1]))
			{
				if(px[i] < minx && px[i] > maxr)
				{
					maxr = px[i];
				}
				if(px[i] > maxx && px[i] < minr)
				{
					minr = px[i];
				}
			}
		}
		if(px[0] == px[i-1] && miny < max(py[0], py[i-1]) && maxy > min(py[0], py[i-1]))
		{
			if(px[0] < minx && px[0] > maxr)
			{
				maxr = px[0];
			}
			if(px[0] > maxx && px[0] < minr)
			{
				minr = px[0];
			}
		}
		if(maxr != -INF && minr != INF)
		{
			return 1;
		}
		if(maxr != -INF)
		{
			bx1 = maxr;
			bx2 = maxx;
		}
		else
		{
			bx1 = minx;
			bx2 = minr;
		}
		minx = bx1;
		maxx = bx2;
		for(i=1, maxr=-INF, minr=INF; i<n; i++)
		{
			if(py[i] == py[i-1] && minx < max(px[i], px[i-1]) && maxx > min(px[i], px[i-1]))
			{
				if(py[i] <= miny && py[i] > maxr)
				{
					maxr = py[i];
				}
				if(py[i] >= maxy && py[i] < minr)
				{
					minr = py[i];
				}
			}
		}
		if(py[0] == py[i-1] && minx < max(px[0], px[i-1]) && maxx > min(px[0], px[i-1]))
		{
			if(py[0] <= miny && py[0] > maxr)
			{
				maxr = py[0];
			}
			if(py[0] >= maxy && py[0] < minr)
			{
				minr = py[0];
			}
		}
		by1 = maxr;
		by2 = minr;
	}
	else
	{
		for(i=1, maxr=-INF, minr=INF; i<n; i++)
		{
			if(py[i] == py[i-1] && minx < max(px[i], px[i-1]) && maxx > min(px[i], px[i-1]))
			{
				if(py[i] < miny && py[i] > maxr)
				{
					maxr = py[i];
				}
				if(py[i] > maxy && py[i] < minr)
				{
					minr = py[i];
				}
			}
		}
		if(py[0] == py[i-1] && minx < max(px[0], px[i-1]) && maxx > min(px[0], px[i-1]))
		{
			if(py[0] < miny && py[0] > maxr)
			{
				maxr = py[0];
			}
			if(py[0] > maxy && py[0] < minr)
			{
				minr = py[0];
			}
		}
		if(maxr != -INF && minr != INF)
		{
			return 1;
		}
		if(maxr != -INF)
		{
			by1 = maxr;
			by2 = maxy;
		}
		else
		{
			by1 = miny;
			by2 = minr;
		}
		miny = by1;
		maxy = by2;
		for(i=1, maxr=-INF, minr=INF; i<n; i++)
		{
			if(px[i] == px[i-1] && miny < max(py[i], py[i-1]) && maxy > min(py[i], py[i-1]))
			{
				if(px[i] <= minx && px[i] > maxr)
				{
					maxr = px[i];
				}
				if(px[i] >= maxx && px[i] < minr)
				{
					minr = px[i];
				}
			}
		}
		if(px[0] == px[i-1] && miny < max(py[0], py[i-1]) && maxy > min(py[0], py[i-1]))
		{
			if(px[0] <= minx && px[0] > maxr)
			{
				maxr = px[0];
			}
			if(px[0] >= maxx && px[0] < minr)
			{
				minr = px[0];
			}
		}
		bx1 = maxr;
		bx2 = minr;
	}
	return 0;
}

void setarea()
{
	lx = max(lx, bx1);
	ly = max(ly, by1);
	rx = min(rx, bx2);
	ry = min(ry, by2);
}

int getarea()
{
	if(lx > rx || ly > ry)
	{
		return -1;
	}
	return 0;
}

int main()
{
	int cas, i;
	cas = 0;
	while(scanf("%d", &n) == 1)
	{
		if(!n)
		{
			break;
		}
		for(i=0; i<n; i++)
		{
			scanf("%d%d", &px[i], &py[i]);
		}
		lx = ly = -INF;
		rx = ry = INF;
		printf("Floor #%d\n", ++cas);
		for(i=1; i<n; i++)
		{
			if(getrect(px[i], py[i], px[i-1], py[i-1]))
			{
				break;
			}
			setarea();
			if(getarea() == -1)
			{
				break;
			}
		}
		if(i == n)
		{
			if(getrect(px[0], py[0], px[i-1], py[i-1]))
			{
				i = 0;
			}
			else
			{
				setarea();
				if(getarea() == -1)
				{
					i = 0;
				}
			}
		}
		if(i == n)
		{
			printf("Surveillance is possible.\n\n");
		}
		else
		{
			printf("Surveillance is impossible.\n\n");
		}
	}
	return 0;
}
