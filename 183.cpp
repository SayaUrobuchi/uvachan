#include <stdio.h>
#include <string.h>

#define MAPSIZE 205

char *ptr;
char map[MAPSIZE][MAPSIZE];
char final[100005];

int getachar()
{
	char now;
	if((now=getchar()) == '\n')
	{
		while((now=getchar()) == '\n');
	}
	return now;
}

void output(char *s)
{
	int i, l;
	for(i=0, l=strlen(s); i<l; i+=50, s+=50)
	{
		printf("%.50s\n", s);
	}
}

void gettypeD(int x1, int y1, int x2, int y2)
{
	int i, j, cx, cy;
	if(x1 == x2 || y1 == y2)
	{
		return;
	}
	/*printf("%d %d %d %d\n", x1, y1, x2, y2);*/
	for(i=x1; i<x2; i++)
	{
		for(j=y1; j<y2; j++)
		{
			if(map[i][j] != map[x1][y1])
			{
				break;
			}
		}
		if(j < y2)
		{
			break;
		}
	}
	if(i < x2)
	{
		*(ptr++) = 'D';
		cx = x1 + ((x2 - x1 + 1) >> 1);
		cy = y1 + ((y2 - y1 + 1) >> 1);
		gettypeD(x1, y1, cx, cy);
		gettypeD(x1, cy, cx, y2);
		gettypeD(cx, y1, x2, cy);
		gettypeD(cx, cy, x2, y2);
	}
	else
	{
		*(ptr++) = map[x1][y1];
	}
}

void gettypeB(int x1, int y1, int x2, int y2)
{
	int now, i, j, cx, cy;
	if(x1 == x2 || y1 == y2)
	{
		return;
	}
	now = getachar();
	if(now == 'D')
	{
		cx = x1 + ((x2 - x1 + 1) >> 1);
		cy = y1 + ((y2 - y1 + 1) >> 1);
		gettypeB(x1, y1, cx, cy);
		gettypeB(x1, cy, cx, y2);
		gettypeB(cx, y1, x2, cy);
		gettypeB(cx, cy, x2, y2);
	}
	else
	{
		for(i=x1; i<x2; i++)
		{
			for(j=y1; j<y2; j++)
			{
				map[i][j] = now;
			}
		}
	}
}

int main()
{
	int n, m, i, j, buf;
	while(buf=getachar())
	{
		if(buf == '#')
		{
			break;
		}
		ptr = final;
		scanf("%d%d", &n, &m);
		if(buf == 'B')
		{
			printf("D%4d%4d\n", n, m);
			for(i=0; i<n; i++)
			{
				for(j=0; j<m; j++)
				{
					map[i][j] = getachar();
				}
			}
			gettypeD(0, 0, n, m);
			*ptr = 0;
			output(final);
		}
		else
		{
			printf("B%4d%4d\n", n, m);
			gettypeB(0, 0, n, m);
			for(i=0; i<n; i++)
			{
				map[i][m] = 0;
				/*printf("%s\n", map[i]);*/
				strcpy(ptr, map[i]);
				ptr += m;
			}
			*ptr = 0;
			output(final);
		}
	}
	return 0;
}
