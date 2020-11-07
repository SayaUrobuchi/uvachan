#include <iostream>

int ucnt;
int used[128][128];
int qx[128*128*2], qy[128*128*2], qs[128*128*2];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int main()
{
	int n, m, i, j, nx, ny, ans, k;
	while (scanf("%d%d%d", &n, &m, &j) == 3)
	{
		ucnt++;
		for (i=0; i<j; i++)
		{
			scanf("%d%d", &nx, &ny);
			if (used[nx][ny] != ucnt)
			{
				used[nx][ny] = ucnt;
				qx[i] = nx;
				qy[i] = ny;
				qs[i] = 1;
			}
		}
		for (j=i, i=0, ans=1; i<j; i++)
		{
			if (qs[i] > ans)
			{
				ans = qs[i];
			}
			for (k=0; k<4; k++)
			{
				nx = qx[i] + dx[k];
				ny = qy[i] + dy[k];
				if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && used[nx][ny] != ucnt)
				{
					used[nx][ny] = ucnt;
					qx[j] = nx;
					qy[j] = ny;
					qs[j] = qs[i]+1;
					j++;
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
