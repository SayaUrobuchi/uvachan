#include <iostream>

const int LEFT = (1<<0);
const int DOWN = (1<<1);
const int RIGHT = (1<<2);
const int UP = (1<<3);

int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};
int n, m;
int ucnt, used[64][64];
int dir[64][64];
int reach;
bool cycle, escape;
int sx[2], sy[2];

bool is_entry(int x, int y)
{
	return (x == 0 && !(dir[x][y] & UP)) || (x == n-1 && !(dir[x][y] & DOWN))
			|| (y == 0 && !(dir[x][y] & LEFT)) || (y == m-1 && !(dir[x][y] & RIGHT));
}

void travel(int x, int y, int d)
{
	int i, nx, ny;
	used[x][y] = ucnt;
	if (x == sx[1] && y == sy[1])
	{
		escape = true;
	}
	reach++;
	for (i=0; i<4; i++)
	{
		if (i != d && !(dir[x][y] & (1<<i)))
		{
			nx = x + dx[i];
			ny = y + dy[i];
			if (nx >= 0 && nx < n && ny >= 0 && ny < m)
			{
				if (used[nx][ny] == ucnt)
				{
					cycle = true;
				}
				else
				{
					travel(nx, ny, (i+2)&3);
				}
			}
		}
	}
}

int main()
{
	int i, j, k;
	while (scanf("%d%d", &n, &m) == 2)
	{
		if (n == 0 && m == 0)
		{
			break;
		}
		for (i=0, k=0; i<n; i++)
		{
			for (j=0; j<m; j++)
			{
				scanf("%1x", &dir[i][j]);
				if (is_entry(i, j))
				{
					sx[k] = i;
					sy[k] = j;
					k++;
				}
			}
		}
		reach = 0;
		++ucnt;
		cycle = false;
		escape = false;
		travel(sx[0], sy[0], -1);
		if (!escape)
		{
			puts("NO SOLUTION");
		}
		else if (reach != n*m)
		{
			puts("UNREACHABLE CELL");
		}
		else if (cycle)
		{
			puts("MULTIPLE PATHS");
		}
		else
		{
			puts("MAZE OK");
		}
	}
	return 0;
}
