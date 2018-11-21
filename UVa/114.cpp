#include <stdio.h>
#include <string.h>

char way[4][2]={{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
int ary[2500][2], map[50][50];

char valid(int m, int n, int x, int y)
{
	return x && x < m-1 && y && y < n-1;
}

int main()
{
	int m, n, l, c, p, x, y, d, s, t, ans, xtemp, ytemp;
	memset(map, -1, sizeof(map));
	scanf("%d%d%d%d", &m, &n, &c, &p);
	while(p--)
	{
		scanf("%d%d%d%d", &x, &y, &ary[p][0], &ary[p][1]);
		map[x-1][y-1] = p;
	}
	ans = 0;
	while(scanf("%d%d%d%d", &x, &y, &d, &l) == 4)
	{
		s = 0;
		x--;
		y--;
		while(l > 0)
		{
			xtemp = x + way[d][0];
			ytemp = y + way[d][1];
			l--;
			if(valid(m, n, xtemp, ytemp))
			{
				if((t = map[xtemp][ytemp]) == -1)
				{
					x = xtemp;
					y = ytemp;
				}
				else
				{
					if(l > 0)
					{
						s += ary[t][0];
						l -= ary[t][1];
						d--;
						if(d < 0)
						{
							d += 4;
						}
					}
				}
			}
			else
			{
				l -= c;
				d--;
				if(d < 0)
				{
					d += 4;
				}
			}
		}
		ans += s;
		printf("%d\n", s);
	}
	printf("%d\n", ans);
	return 0;
}
