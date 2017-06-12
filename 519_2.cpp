#include <stdio.h>
#include <string.h>

#define TOP 0
#define RIGHT 1
#define BOTTOM 2
#define LEFT 3
#define FLAT 'F'

int n, m, o, t;
int num[36];
int board[6][6];
char shape[36][5];
char buf[1005];

int getnum(char *s)
{
	int i;
	for(i=0; i<t; i++)
	{
		if(!strcmp(shape[i], s))
		{
			return i;
		}
	}
	strcpy(shape[t++], s);
	return i;
}

int dfs(int x, int y)
{
	int i;
	if(y >= m)
	{
		x++;
		y = 0;
	}
	if(x >= n)
	{
		return 1;
	}
	for(i=0; i<o; i++)
	{
		if(num[i])
		{
			if((!x && shape[i][TOP] == FLAT) || (x && shape[i][TOP] != FLAT && shape[i][TOP] != shape[board[x-1][y]][BOTTOM]))
			{
				if((!y && shape[i][LEFT] == FLAT) || (y && shape[i][LEFT] != FLAT && shape[i][LEFT] != shape[board[x][y-1]][RIGHT]))
				{
					if((x == n - 1 && shape[i][BOTTOM] == FLAT) || (x < n - 1 && shape[i][BOTTOM] != FLAT))
					{
						if((y == m - 1 && shape[i][RIGHT] == FLAT) || (y < m - 1 && shape[i][RIGHT] != FLAT))
						{
							num[i]--;
							board[x][y] = i;
							if(dfs(x, y+1))
							{
								return 1;
							}
							num[i]++;
						}
					}
				}
			}
		}
	}
	return 0;
}

int main()
{
	int i;
	while(scanf("%d%d", &n, &m) == 2)
	{
		if(!n && !m)
		{
			break;
		}
		memset(num, 0, sizeof(num));
		t = 0;
		for(i=0, o=n*m; i<o; i++)
		{
			scanf("%s", buf);
			num[getnum(buf)]++;
		}
		if(dfs(0, 0))
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
	return 0;
}
