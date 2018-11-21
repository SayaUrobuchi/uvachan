#include <stdio.h>
#include <string.h>

#define LEFT 2
#define RIGHT 0
#define FORWARD 3
#define BACK 1

int n, m, map[11][11], xstep[4]={0, 1, 0, -1}, ystep[4]={1, 0, -1, 0}, 
	from[10000], counter;
int dice[7][7] = {{0, 0, 0, 0, 0, 0, 0}, 
				  {0, 0, 3, 5, 2, 4, 0}, 
				  {0, 4, 0, 1, 6, 0, 3}, 
				  {0, 2, 6, 0, 0, 1, 5}, 
				  {0, 5, 1, 0, 0, 6, 2}, 
				  {0, 3, 0, 6, 1, 0, 4}, 
				  {0, 0, 4, 2, 5, 3, 0}};
char used[10000], name[30];

typedef struct data
{
	int x, y, top, front, right;
}data;

data queue[10000];

int getright(int top, int front)
{
	return dice[top][front];
}

int valid(int x, int y, int top)
{
	return x >= 0 && x < n && y >= 0 && y < m && (map[x][y] == -1 || map[x][y] == top);
}

int encode(int x, int y, int top, int front)
{
	return x + y * 11 + top * 121 + front * 847;
}

void getnewdice(int top, int front, int right, int *t, int *f, int *r, int dir)
{
	if(dir == LEFT)
	{
		*t = right;
		*r = 7 - top;
		*f = front;
	}
	else if(dir == RIGHT)
	{
		*r = top;
		*t = 7 - right;
		*f = front;
	}
	else if(dir == FORWARD)
	{
		*t = front;
		*f = 7 - top;
		*r = right;
	}
	else if(dir == BACK)
	{
		*f = top;
		*t = 7 - front;
		*r = right;
	}
}

int bfs(int sx, int sy, int top, int front, int right)
{
	int i, j, k, tx, ty, code;
	data temp;
	memset(used, 0, sizeof(used));
	used[encode(sx, sy, top, front)] = 1;
	queue[0] = (data){sx, sy, top, front, right};
	for(i=0, j=1; i<j; i++)
	{
		temp = queue[i];
		/*printf("TOP %d, loc (%d, %d).\n", temp.top, temp.x+1, temp.y+1);*/
		for(k=0; k<4; k++)
		{
			tx = temp.x + xstep[k];
			ty = temp.y + ystep[k];
			if(valid(tx, ty, temp.top))
			{
				/*printf("TOP %d, loc (%d, %d), %d.\n", temp.top, temp.x+1, temp.y+1, map[tx][ty]);*/
				getnewdice(temp.top, temp.front, temp.right, &top, &front, &right, k);
				if(used[code=encode(tx, ty, top, front)] == 0)
				{
					used[code] = 1;
					from[j] = i;
					queue[j++] = (data){tx, ty, top, front, right};
				}
				if(tx == sx && ty == sy)
				{
					used[code] = 1;
					from[j] = i;
					queue[j++] = (data){tx, ty, top, front, right};
					return j-1;
				}
			}
		}
	}
	return -1;
}

void output(int now)
{
	if(now != 0)
	{
		output(from[now]);
	}
	if(counter != 0)
	{
		putchar(',');
	}
	if(counter % 9 == 0)
	{
		printf("\n  ");
	}
	printf("(%d,%d)", queue[now].x+1, queue[now].y+1);
	counter++;
}

int main()
{
	int i, j, sx, sy, top, front, right, final;
	while(scanf("%s", name) == 1)
	{
		if(strcmp(name, "END") == 0)
		{
			break;
		}
		scanf("%d%d%d%d%d%d", &n, &m, &sx, &sy, &top, &front);
		sx--, sy--;
		for(i=0; i<n; i++)
		{
			for(j=0; j<m; j++)
			{
				scanf("%d", &map[i][j]);
			}
		}
		right = getright(top, front);
		final = bfs(sx, sy, top, front, right);
		printf("%s", name);
		if(final == -1)
		{
			printf("\n  No Solution Possible\n");
		}
		else
		{
			counter = 0;
			output(final);
			putchar('\n');
		}
	}
	return 0;
}
