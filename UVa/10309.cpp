#include <stdio.h>
#include <string.h>

char map[10][11], way[5][2] = {{0, 0}, {0, 1}, {0, -1}, {1, 0}, {-1, 0}};

char calc(int x, int y)
{
	if(x > 9 || x < 0 || y > 9 || y < 0)
	{
		return 0;
	}
	if(map[x][y] == '#')
	{
		map[x][y] = 'O';
		return 1;
	}
	map[x][y] = '#';
	return -1;
}

char dfs(int x, int y, int press, int light)
{
	char res, count, i;
	if(press > 100)
	{
		return 0;
	}
	if(!light)
	{
		return press;
	}
	if(y == 10)
	{
		y = 0;
		x++;
		if(x == 10)
		{
			return 0;
		}
	}
	if(x)
	{
		if(map[x-1][y] == 'O')
		{
			count = 0;
			for(i=0; i<5; i++)
			{
				count += calc(x + way[i][0], y + way[i][1]);
			}
			res = dfs(x, y+1, press+1, light+count);
			for(i=0; i<5; i++)
			{
				calc(x + way[i][0], y + way[i][1]);
			}
			return res;
		}
		else
		{
			return dfs(x, y+1, press, light);
		}
	}
	else
	{
		count = 0;
		for(i=0; i<5; i++)
		{
			count += calc(x + way[i][0], y + way[i][1]);
		}
		res = dfs(x, y+1, press+1, light+count);
		for(i=0; i<5; i++)
		{
			calc(x + way[i][0], y + way[i][1]);
		}
		if(res)
		{
			return res;
		}
		return dfs(x, y+1, press, light);
	}
}

int main()
{
	char name[1001], i, j, light, res;
	while(gets(name))
	{
		if(!strcmp(name, "end"))
		{
			break;
		}
		light = 0;
		for(i=0; i<10; i++)
		{
			gets(map[i]);
			for(j=0; j<10; j++)
			{
				if(map[i][j] == 'O')
				{
					light++;
				}
			}
		}
		if(!light)
		{
			printf("%s 0\n", name);
		}
		else
		{
			res = dfs(0, 0, 0, light);
			if(res)
			{
				printf("%s %d\n", name, res);
			}
			else
			{
				printf("%s -1\n", name);
			}
		}
	}
	return 0;
}
