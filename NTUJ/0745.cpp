#include <stdio.h>
#include <string.h>

#define LEFT 3

int n, m;
int len[205];
int dx[]={1, 0, -1, 0}, dy[]={0, 1, 0, -1};
int used[205][205];
int vis[205][205];
int var[128];
char map[205][205];

int is_var(int c)
{
	return c>='A' && c<='Z';
}

int get_sym(int x, int y)
{
	int i, temp;
	if(used[x][y])
	{
		return 0;
	}
	used[x][y] = 1;
	if(map[x][y] == '#')
	{
		return 0;
	}
	else if(map[x][y] != ' ')
	{
		return map[x][y];
	}
	else
	{
		for(i=0; i<4; i++)
		{
			temp = get_sym(x+dx[i], y+dy[i]);
			if(temp)
			{
				return temp;
			}
		}
		return 0;
	}
}

int calc(int x, int y, int dir)
{
	int i, tx, ty, temp, sym, r1, r0, res;
	if(x < 0 || x >= n || y < 0 || y >= len[x])
	{
		return -1;
	}
	if(vis[x][y]<100)
	{
		return vis[x][y];
	}
	vis[x][y] = -1;
	if(map[x][y] == ' ')
	{
		return -1;
	}
	else if(map[x][y] == '-' || map[x][y] == '|' || map[x][y] == 'x')
	{
		if(map[x][y] == '-' && dir%2 == 0)
		{
			return -1;
		}
		else if(map[x][y] == '|' && dir%2)
		{
			return -1;
		}
		return vis[x][y] = calc(x+dx[dir], y+dy[dir], dir);
	}
	else if(map[x][y] == '=')
	{
		if(dir % 2 == 0)
		{
			return -1;
		}
		return vis[x][y] = calc(x+dx[dir], y+dy[dir], dir);
	}
	else if(map[x][y] == '+')
	{
		for(i=0; i<4; i++)
		{
			if(i != (dir+2)%4)
			{
				tx = x + dx[i];
				ty = y + dy[i];
				if(tx >= 0 && tx < n && ty >= 0 && ty < len[tx])
				{
					if(map[tx][ty] == '|' && i % 2)
					{
						continue;
					}
					else if((map[tx][ty] == '-' || map[tx][ty] == '=') && i % 2 == 0)
					{
						continue;
					}
					temp = calc(x+dx[i], y+dy[i], i);
					if(temp != -1)
					{
						return vis[x][y] = temp;
					}
				}
			}
		}
		return -1;
	}
	else if(map[x][y] == 'o')
	{
		temp = calc(x+dx[dir], y+dy[dir], dir);
		return vis[x][y] = (temp==-1?temp:!temp);
	}
	else if(map[x][y] == '1' || map[x][y] == '0')
	{
		return vis[x][y] = map[x][y]-'0';
	}
	else if(map[x][y] >= 'A' && map[x][y] <= 'Z')
	{
		return -1;
	}
	else if(map[x][y] == '#')
	{
		if(dir != LEFT)
		{
			return -1;
		}
		for(tx=x, ty=y; tx>=0&&map[tx][ty]=='#'; tx--);
		for(tx++; ty>=0&&map[tx][ty]=='#'; ty--);
		ty++;
		memset(used, 0, sizeof(used));
		sym = get_sym(tx+1, ty+1);
		for(r1=r0=0; tx<n; tx++)
		{
			if(map[tx][ty] != '#')
			{
				break;
			}
			if(ty > 0 && map[tx][ty-1] == '=')
			{
				res = calc(tx, ty-1, LEFT);
				if(res != -1)
				{
					if(res)
					{
						r1++;
					}
					else
					{
						r0++;
					}
				}
			}
		}
		if(sym == '1')
		{
			return vis[x][y] = (r1>0);
		}
		else if(sym == '&')
		{
			return vis[x][y] = (r0==0);
		}
		else
		{
			return vis[x][y] = r1%2;
		}
	}
	return -1;
}

int main()
{
	int i, j;
	n = 0;
	while(gets(map[n]))
	{
		if(*map[n] == '*')
		{
			memset(var, -1, sizeof(var));
			for(i=0; i<n; i++)
			{
				for(j=0; j<len[i]; j++)
				{
					if(is_var(map[i][j]) && j && map[i][j-1] == '=')
					{
						memset(vis, 1, sizeof(vis));
						var[map[i][j]] = calc(i, j-1, LEFT);
					}
				}
			}
			for(i='A'; i<='Z'; i++)
			{
				if(var[i] != -1)
				{
					printf("%c=%d\n", i, var[i]);
				}
			}
			printf("\n");
			n = 0;
			continue;
		}
		len[n] = strlen(map[n]);
		n++;
	}
	return 0;
}
