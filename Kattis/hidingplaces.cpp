#include <iostream>
#include <algorithm>

const int N = 16;
const int NN = N*N;

int ucnt;
int used[N][N];
int qx[NN], qy[NN], qs[NN], idx[NN];
int dx[] = {1, 1, -1, -1, 2, 2, -2, -2};
int dy[] = {2, -2, 2, -2, 1, -1, 1, -1};

bool comp(int p, int q)
{
	if (qy[p] != qy[q])
	{
		return qy[p] > qy[q];
	}
	return qx[p] < qx[q];
}

void bfs(int sx, int sy)
{
	int i, j, k, x, y, s, tx, ty, ts;
	++ucnt;
	qx[0] = sx;
	qy[0] = sy;
	qs[0] = 0;
	for (i=0, j=1; i<j; i++)
	{
		x = qx[i];
		y = qy[i];
		s = qs[i];
		for (k=0; k<8; k++)
		{
			tx = x + dx[k];
			ty = y + dy[k];
			ts = s + 1;
			if (tx >= 0 && tx < 8 && ty >= 0 && ty < 8 && used[tx][ty] != ucnt)
			{
				used[tx][ty] = ucnt;
				qx[j] = tx;
				qy[j] = ty;
				qs[j] = ts;
				++j;
			}
		}
	}
	--j;
	s = qs[j];
	printf("%d", s);
	for (i=j, k=0; i>=0&&qs[i]==s; i--, k++)
	{
		idx[k] = i;
	}
	std::sort(idx, idx+k, comp);
	for (i=0; i<k; i++)
	{
		printf(" %c%c", qx[idx[i]]+'a', qy[idx[i]]+'1');
	}
	puts("");
}

int main()
{
	int count;
	char buf[8];
	scanf("%d", &count);
	while (count--)
	{
		scanf("%s", buf);
		bfs(buf[0]-'a', buf[1]-'1');
	}
	return 0;
}
