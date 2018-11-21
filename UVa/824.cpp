#include <stdio.h>

int map[10][10];
int wayy[8] = {1, 1, 0, -1, -1, -1, 0, 1};
int wayx[8] = {0, -1, -1, -1, 0, 1, 1, 1};

int adjust(int d)
{
	if(d < 0)
	{
		return d+8;
	}
	else if(d >= 8)
	{
		return d-8;
	}
	return d;
}

int main()
{
	int i, x, y, d, cx, cy, dir, adx, ady, type;
	while(scanf("%d", &cx) == 1)
	{
		if(cx == -1)
		{
			break;
		}
		scanf("%d%d", &cy, &dir);
		adx = cx - 2;
		ady = cy - 2;
		cx -= adx;
		cy -= ady;
		/*printf("%d %d\n", cx, cy);*/
		for(i=0; i<8; i++)
		{
			scanf("%d%d%d", &x, &y, &type);
			map[x-adx][y-ady] = type;
			/*printf("%d %d: %d\n", x-adx, y-ady, type);*/
		}
		for(i=-2; i<6; i++)
		{
			d = adjust(dir+i);
			x = cx + wayx[d];
			y = cy + wayy[d];
			/*printf("%d: %d %d\n", d, x, y);*/
			if(map[x][y])
			{
				printf("%d\n", d);
				break;
			}
		}
	}
	return 0;
}
