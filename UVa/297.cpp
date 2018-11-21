#include <stdio.h>
#include <string.h>

int area;
int map[32][32];
char buf[3000];
char *ptr;

int recursion(int x1, int x2, int y1, int y2)
{
	int i, j, xside, yside;
	char code;
	xside = (x2-x1)/2;
	yside = (y2-y1)/2;
	code = *(ptr++);
	if(code == 'p')
	{
		recursion(x1+xside, x2, y1, y2-yside);
		recursion(x1, x2-xside, y1, y2-yside);
		recursion(x1, x2-xside, y1+yside, y2);
		recursion(x1+xside, x2, y1+yside, y2);
	}
	else if(code == 'f')
	{
		for(i=x1; i<x2; i++)
		{
			for(j=y1; j<y2; j++)
			{
				map[i][j] = 1;
			}
		}
	}
}

int main()
{
	int count, i, j;
	scanf("%d", &count);
	gets(buf);
	while(count--)
	{
		memset(map, 0, sizeof(map));
		gets(buf);
		ptr = buf;
		recursion(0, 32, 0, 32);
		gets(buf);
		ptr = buf;
		recursion(0, 32, 0, 32);
		for(i=0, area=0; i<32; i++)
		{
			for(j=0; j<32; j++)
			{
				area += map[i][j];
			}
		}
		printf("There are %d black pixels.\n", area);
	}
	return 0;
}
