#include <stdio.h>

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int tbl[128];
char buf[128];

int main()
{
	int n, m, o, x, y, rx, ry, dir, t;
	tbl['u'] = 1;
	tbl['d'] = 3;
	tbl['r'] = 0;
	tbl['l'] = 2;
	while (scanf("%d%d", &m, &n) == 2)
	{
		if (n == 0 && m == 0)
		{
			break;
		}
		scanf("%d", &o);
		for (x=0, y=0, rx=0, ry=0; o--; )
		{
			scanf("%s%d", buf, &t);
			dir = tbl[*buf];
			x += dx[dir]*t;
			y += dy[dir]*t;
			rx += dx[dir]*t;
			ry += dy[dir]*t;
			if (rx < 0)
			{
				rx = 0;
			}
			else if (rx > n-1)
			{
				rx = n-1;
			}
			if (ry < 0)
			{
				ry = 0;
			}
			else if (ry > m-1)
			{
				ry = m-1;
			}
		}
		printf("Robot thinks %d %d\n", y, x);
		printf("Actually at %d %d\n\n", ry, rx);
	}
	return 0;
}
