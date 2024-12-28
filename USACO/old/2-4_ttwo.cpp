/*
	ID: sa072682
	LANG: C
	TASK: ttwo
*/
#include <stdio.h>

int cx, cy, c, cd, fx, fy, fd;
char map[10][11], chk[10][10][4][10][10][4];
int way[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

char valid(int x, int y)
{
	return x > -1 && x < 10 && y > -1 && y < 10;
}

void cowmove()
{
	int tx, ty;
	tx = cx + way[cd][0];
	ty = cy + way[cd][1];
	if(valid(tx, ty) && map[tx][ty] != '*')
	{
		cx = tx;
		cy = ty;
	}
	else
	{
		cd++;
		cd %= 4;
	}
	c++;
}

void farmermove()
{
	int tx, ty;
	tx = fx + way[fd][0];
	ty = fy + way[fd][1];
	if(valid(tx, ty) && map[tx][ty] != '*')
	{
		fx = tx;
		fy = ty;
	}
	else
	{
		fd++;
		fd %= 4;
	}
}

int main()
{
	int i, j, x, y, tx, ty, dir, step;
	freopen("ttwo.in", "r", stdin);
	freopen("ttwo.out", "w", stdout);
	for(i=0; i<10; i++)
	{
		gets(map[i]);
		for(j=0; j<10; j++)
		{
			if(map[i][j] == 'F')
			{
				fx = i;
				fy = j;
				fd = 0;
			}
			else if(map[i][j] == 'C')
			{
				c = 0;
				cx = i;
				cy = j;
				cd = 0;
			}
		}
	}
	while(1)
	{
		cowmove();
		farmermove();
		if(fx == cx && fy == cy)
		{
			break;
		}
		if(chk[fx][fy][fd][cx][cy][cd])
		{
			break;
		}
		chk[fx][fy][fd][cx][cy][cd] = 1;
	}
	if(fx == cx && fy == cy)
	{
		printf("%d\n", c);
	}
	else
	{
		printf("0\n");
	}
	scanf(" ");
	return 0;
}
