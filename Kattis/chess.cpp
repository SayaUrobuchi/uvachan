#include <iostream>

int dx[] = {1, 1, -1, -1};
int dy[] = {1, -1, 1, -1};
int ucnt, used[16][16];
int from[128], qx[128], qy[128], qs[128];
char s[128], t[128];

void recurs(int cur)
{
	if (cur)
	{
		recurs(from[cur]);
	}
	printf(" %c %d", qx[cur]+'A', qy[cur]+1);
}

int main()
{
	int count, i, j, k, l, x, y, sx, sy, ex, ey, nx, ny, d;
	scanf("%d", &count);
	while (count--)
	{
		scanf(" %[A-Z]%d %[A-Z]%d", s, &sy, t, &ey);
		--sy, --ey;
		sx = *s - 'A';
		ex = *t - 'A';
		if (((sx+sy)&1) != ((ex+ey)&1))
		{
			puts("Impossible");
			continue;
		}
		qx[0] = sx;
		qy[0] = sy;
		qs[0] = 0;
		used[sx][sy] = ++ucnt;
		for (i=0, j=1; i<j; i++)
		{
			x = qx[i];
			y = qy[i];
			d = qs[i];
			if (x == ex && y == ey)
			{
				break;
			}
			for (k=0; k<4; k++)
			{
				for (l=1; ; l++)
				{
					nx = x + dx[k]*l;
					ny = y + dy[k]*l;
					if (nx < 0 || nx >= 8 || ny < 0 || ny >= 8)
					{
						break;
					}
					if (used[nx][ny] != ucnt)
					{
						used[nx][ny] = ucnt;
						qx[j] = nx;
						qy[j] = ny;
						qs[j] = d+1;
						from[j] = i;
						++j;
					}
				}
			}
		}
		printf("%d", d);
		recurs(i);
		puts("");
	}
	return 0;
}
