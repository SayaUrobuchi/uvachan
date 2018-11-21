#include <stdio.h>
#include <string.h>

char tbl[2000][2000];

int main()
{
	int n, i, x, y, sx, sy, tx, ty, s;
	while(scanf("%d%d%d%d%d", &n, &x, &y, &sx, &sy) == 5)
	{
		if(!n && !x && !y && !sx && !sy)
		{
			break;
		}
		s = n + n;
		tx = x % s;
		ty = y % s;
		if((ty && ty < n && tx > n) || (tx && tx < n && ty > n))
		{
			printf("After 0 jumps the flea lands at (%d, %d).\n", x, y);
			continue;
		}
		memset(tbl, 0, sizeof(tbl));
		tbl[x%s][y%s] = 1;
		for(i=1; ; i++)
		{
			x += sx;
			y += sy;
			tx = x % s;
			ty = y % s;
			if(tbl[tx][ty])
			{
				printf("The flea cannot escape from black squares.\n");
				break;
			}
			if((ty && ty < n && tx > n) || (tx && tx < n && ty > n))
			{
				printf("After %d jumps the flea lands at (%d, %d).\n", i, x, y);
				break;
			}
			tbl[tx][ty] = 1;
		}
	}
	return 0;
}
