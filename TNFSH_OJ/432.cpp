#include<iostream>
using namespace std;

int qx[1024*1024], qy[1024*1024], used[1024][1024];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int main() {
	int n, m, p, q, t, ex, ey, x, y, tx, ty, i, j, k, cnt;
	cnt = 0;
	while (scanf("%d%d", &n, &m) == 2)
	{
		++cnt;
		scanf("%d%d", &p, &q);
		qx[0] = p;
		qy[0] = q;
		used[p][q] = cnt;
		scanf("%d%d", &ex, &ey);
		scanf("%d", &t);
		for (i=0; i<t; i++)
		{
			scanf("%d%d", &p, &q);
			used[p][q] = cnt;
		}
		for (i=0, j=1; i<j; i++)
		{
			x = qx[i];
			y = qy[i];
			if (x == ex && y == ey)
			{
				break;
			}
			for (k=0; k<4; k++)
			{
				tx = x + dx[k];
				ty = y + dy[k];
				if (tx >= 1 && tx <= n && ty >= 1 && ty <= m && used[tx][ty] != cnt)
				{
					qx[j] = tx;
					qy[j] = ty;
					j++;
					used[tx][ty] = cnt;
				}
			}
		}
		puts(i < j ? "Cool!" : "Harakiri!");
	}
	return 0;
}
