#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1005;
const int N2 = 2048;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int xn, yn;
int x0[N], y0[N], x1[N], y1[N];
int px[N2], py[N2];
int cnt[N2][N2], qx[N2*N2], qy[N2*N2];
bool used[N2][N2];

void bfs(int sx, int sy)
{
	int i, j, k, x, y, tx, ty;
	qx[0] = sx;
	qy[0] = sy;
	used[sx][sy] = true;
	for (i=0, j=1; i<j; i++)
	{
		x = qx[i];
		y = qy[i];
		for (k=0; k<4; k++)
		{
			tx = x + dx[k];
			ty = y + dy[k];
			if (tx >= 0 && tx < xn-1 && ty >= 0 && ty < yn-1)
			{
				if (cnt[tx][ty] == 0 && !used[tx][ty])
				{
					used[tx][ty] = true;
					qx[j] = tx;
					qy[j] = ty;
					++j;
				}
			}
		}
	}
}

void uni(int ary[], int &n)
{
	int i, j;
	for (i=0, j=0; i<n; i++)
	{
		if (i == 0 || ary[i] != ary[i-1])
		{
			ary[j] = ary[i];
			++j;
		}
	}
	n = j;
}

int main()
{
	int n, m, o, i, j, lx, ly, rx, ry, ans;
	scanf("%d%d", &n, &m);
	scanf("%d", &o);
	for (i=0, xn=0, yn=0; i<o; i++)
	{
		scanf("%d%d%d%d", &x0[i], &y0[i], &x1[i], &y1[i]);
		px[xn++] = x0[i];
		px[xn++] = x1[i];
		py[yn++] = y0[i];
		py[yn++] = y1[i];
	}
	px[xn++] = 0;
	px[xn++] = n;
	py[yn++] = 0;
	py[yn++] = m;
	sort(px, px+xn);
	uni(px, xn);
	sort(py, py+yn);
	uni(py, yn);
	for (i=0; i<o; i++)
	{
		lx = lower_bound(px, px+xn, x0[i]) - px;
		rx = lower_bound(px, px+xn, x1[i]) - px;
		ly = lower_bound(py, py+yn, y0[i]) - py;
		ry = lower_bound(py, py+yn, y1[i]) - py;
		++cnt[lx][ly];
		--cnt[lx][ry];
		--cnt[rx][ly];
		++cnt[rx][ry];
	}
	for (i=0; i<xn; i++)
	{
		for (j=1; j<yn; j++)
		{
			cnt[i][j] += cnt[i][j-1];
		}
	}
	for (i=1; i<xn; i++)
	{
		for (j=0; j<yn; j++)
		{
			cnt[i][j] += cnt[i-1][j];
		}
	}
	// printf("     ");
	// for (i=0; i<yn; i++)
	// {
		// printf("%3d", py[i]);
	// }
	// puts("");
	// for (i=0; i<xn; i++)
	// {
		// printf("%3d: ", px[i]);
		// for (j=0; j<yn; j++)
		// {
			// printf("%3d", cnt[i][j]);
		// }
		// puts("");
	// }
	for (i=0, ans=0; i<xn-1; i++)
	{
		for (j=0; j<yn-1; j++)
		{
			if (!used[i][j] && cnt[i][j] == 0)
			{
				++ans;
				bfs(i, j);
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}