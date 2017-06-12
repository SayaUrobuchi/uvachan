#include <stdio.h>
#include <stdlib.h>

int count, h, w;
int wayx[4] = {0, 0, 1, -1};
int wayy[4] = {1, -1, 0, 0};
int ary[2500];
char map[51][51];

int comp(const void *p, const void *q)
{
	return *(int*)p - *(int*)q;
}

int valid(int x, int y)
{
	return x > -1 && x < h && y > -1 && y < w;
}

void floodfill2(int x, int y)
{
	int i, tx, ty;
	map[x][y] = '*';
	for(i=0; i<4; i++)
	{
		tx = x + wayx[i];
		ty = y + wayy[i];
		if(valid(tx, ty) && map[tx][ty] == 'X')
		{
			floodfill2(tx, ty);
		}
	}
}

void floodfill(int x, int y)
{
	int i, tx, ty;
	if(map[x][y] == 'X')
	{
		count++;
		floodfill2(x, y);
	}
	map[x][y] = '.';
	for(i=0; i<4; i++)
	{
		tx = x + wayx[i];
		ty = y + wayy[i];
		if(valid(tx, ty) && map[tx][ty] != '.')
		{
			if(map[tx][ty] == 'X')
			{
				count++;
				floodfill2(tx, ty);
			}
			floodfill(tx, ty);
		}
	}
}

int main()
{
	int cas, i, j, k;
	cas = 0;
	while(scanf("%d%d", &w, &h) == 2)
	{
		if(!w && !h)
		{
			break;
		}
		gets(map[0]);
		for(i=0; i<h; i++)
		{
			gets(map[i]);
		}
		for(i=0, k=0; i<h; i++)
		{
			for(j=0; j<w; j++)
			{
				if(map[i][j] != '.')
				{
					count = 0;
					floodfill(i, j);
					ary[k++] = count;
				}
			}
		}
		qsort(ary, k, sizeof(int), comp);
		printf("Throw %d\n%d", ++cas, ary[0]);
		for(i=1; i<k; i++)
		{
			printf(" %d", ary[i]);
		}
		printf("\n\n");
	}
	return 0;
}
