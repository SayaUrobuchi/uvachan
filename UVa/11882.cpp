#include <stdio.h>
#include <string.h>
#include <algorithm>

const int QN = 30000000;
const int HN = QN;
const int PN = 32;

int n, m, ucnt;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int qx[QN], qy[QN], qstep[QN], qstat[QN], qfuture[QN];
char qp[QN][PN];
int heap[HN];
char board[PN][PN];
int used[PN][PN];
int qfx[PN], qfy[PN];

bool comp(int p, int q)
{
	int lval = qstep[p] + qfuture[p];
	int rval = qstep[q] + qfuture[q];
	if (lval != rval)
	{
		return lval < rval;
	}
	int res = strncmp(qp[p], qp[q], std::min(qstep[p], qstep[q]));
	if (res != 0)
	{
		return res < 0;
	}
	return qstep[p] > qstep[q];
}

int is_valid(int p, int q, int stat, int uc)
{
	return p>=0 && p<n && q>=0 && q<m && board[p][q]!='#' && used[p][q]!=uc && !(stat & (1<<(p*m+q)));
}

int get_future(int p, int q, int stat)
{
	int i, j, k, tx, ty;
	ucnt++;
	qfx[0] = p;
	qfy[0] = q;
	used[p][q] = ucnt;
	for (i=0, j=1; i<j; i++)
	{
		for (k=0; k<4; k++)
		{
			tx = qfx[i]+dx[k];
			ty = qfy[i]+dy[k];
			if (is_valid(tx, ty, stat, ucnt))
			{
				used[tx][ty] = ucnt;
				qfx[j] = tx;
				qfy[j] = ty;
				j++;
			}
		}
	}
	return j-1;
}

int main()
{
	int i, j, k, t, hn, cur, x, y, step, stat, future, tx, ty;
	char *path;
	while (scanf("%d%d", &n, &m) == 2)
	{
		if (!n && !m)
		{
			break;
		}
		t = 0;
		for (i=0; i<n; i++)
		{
			scanf("%s", board[i]);
		}
		for (i=0; i<n; i++)
		{
			for (j=0; board[i][j]; j++)
			{
				if (board[i][j] != '#')
				{
					qx[t] = i;
					qy[t] = j;
					qstep[t] = 1;
					qstat[t] = (1 << (i*m+j));
					qfuture[t] = get_future(i, j, 0);
					sprintf(qp[t], "%c", board[i][j]);
					heap[t] = t;
					t++;
				}
			}
		}
		std::make_heap(heap, heap+t, comp);
		hn = t;
		while (hn > 0)
		{
			cur = heap[0];
			std::pop_heap(heap, heap+hn, comp);
			hn--;
			x = qx[cur];
			y = qy[cur];
			step = qstep[cur];
			stat = qstat[cur];
			future = qfuture[cur];
			path = qp[cur];
			if (!future)
			{
				//printf("now: %d, hn: %d\n", cur, hn);
				break;
			}
			for (k=0; k<4; k++)
			{
				tx = x + dx[k];
				ty = y + dy[k];
				if (is_valid(tx, ty, stat, -1))
				{
					qx[t] = tx;
					qy[t] = ty;
					qstep[t] = step+1;
					qstat[t] = (stat | (1 << (tx*m+ty)));
					qfuture[t] = get_future(tx, ty, stat);
					sprintf(qp[t], "%s%c", path, board[tx][ty]);
					heap[hn] = t;
					t++;
					hn++;
					std::push_heap(heap, heap+hn, comp);
				}
			}
		}
		puts(path);
	}
	return 0;
}
