#include <iostream>

int n;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int cx[] = {1, 0, 0};
int cy[] = {1, 0, 0};
int cd[] = {0, 3, 1};
int cmd[64];
char buf[64];
const char *cname[3] = {"Forward", "Left", "Right"};

bool check(int ex, int ey)
{
	int x, y, d, i;
	x = 0;
	y = 0;
	d = 0;
	for (i=0; i<n; i++)
	{
		x += dx[d] * cx[cmd[i]];
		y += dy[d] * cy[cmd[i]];
		d = ((d+cd[cmd[i]]) & 3);
	}
	//printf("final: %d %d\n", x, y);
	return x == ex && y == ey;
}

int main()
{
	int ex, ey, i, j;
	while (scanf("%d%d", &ex, &ey) == 2)
	{
		scanf("%d", &n);
		for (i=0; i<n; i++)
		{
			scanf("%s", buf);
			if (*buf == 'F')
			{
				cmd[i] = 0;
			}
			else if (*buf == 'L')
			{
				cmd[i] = 1;
			}
			else
			{
				cmd[i] = 2;
			}
		}
		for (i=0; i<n; i++)
		{
			for (j=0; j<2; j++)
			{
				cmd[i] = (cmd[i]+1) % 3;
				if (check(ex, ey))
				{
					printf("%d %s\n", i+1, cname[cmd[i]]);
					break;
				}
			}
			cmd[i] = (cmd[i]+1) % 3;
			if (j < 2)
			{
				break;
			}
		}
	}
	return 0;
}
