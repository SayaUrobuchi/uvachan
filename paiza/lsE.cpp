// 5361
#include <stdio.h>
#include <stdlib.h>

#define M 25005
#define TANE 0
#define HN 256
#define T 228
#define L 7
#define W 51

char qbb[M][50][W];
int qs[M], qx[M], qy[M], qd[M], qt[M], dn;
int adx[100], ady[100];
int heap[M], hn;
char (*board)[50][W], (*board2)[50][W];
int used[50][50], uc;
int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
int qqx[2505], qqy[2505];
int sc[2505], scn;
int resx[2505], resy[2505], resz[2505], rs[2505], reszx[T], reszy[T], rn;
int n, m, o, ans, best;

int comp(const void *p, const void *q)
{
	return *(int*)q-*(int*)p;
}


int comp2(const void *p, const void *q)
{
	return resz[*(int*)q]-resz[*(int*)p];
}

void heapup(int t)
{
	while (t>1)
	{
		int p = (t>>1);
		if (qs[heap[t]] > qs[heap[p]])
		{
			int temp = heap[t];
			heap[t] = heap[p];
			heap[p] = temp;
			t = p;
		}
		else
		{
			return;
		}
	}
}

void heapdown(int t)
{
	while ((t>>1)<=hn)
	{
		int l=(t>>1);
		int r=l+1;
		if (r>hn || qs[heap[l]]>qs[heap[r]])
		{
			if (qs[heap[t]] < qs[heap[l]])
			{
				int temp = heap[t];
				heap[t] = heap[l];
				heap[l] = temp;
				t = l;
			}
			else
			{
				return;
			}
		}
		else
		{
			if (qs[heap[t]] < qs[heap[r]])
			{
				int temp = heap[t];
				heap[t] = heap[r];
				heap[r] = temp;
				t = r;
			}
			else
			{
				return;
			}
		}
	}
}

int fill(char board[][W], int x, int y)
{
	int i, j, k, tx, ty;
	qqx[0] = x;
	qqy[0] = y;
	used[x][y] = uc;
	for (i=0, j=1; i<j; i++)
	{
		tx = qqx[i];
		ty = qqy[i]+1;
		if (tx >= 0 && tx < n && ty >= 0 && ty < m && used[tx][ty] != uc && board[tx][ty] == board[x][y])
		{
			used[tx][ty] = uc;
			qqx[j] = tx;
			qqy[j] = ty;
			j++;
		}
		tx = qqx[i]+1;
		ty = qqy[i];
		if (tx >= 0 && tx < n && ty >= 0 && ty < m && used[tx][ty] != uc && board[tx][ty] == board[x][y])
		{
			used[tx][ty] = uc;
			qqx[j] = tx;
			qqy[j] = ty;
			j++;
		}
		tx = qqx[i];
		ty = qqy[i]-1;
		if (tx >= 0 && tx < n && ty >= 0 && ty < m && used[tx][ty] != uc && board[tx][ty] == board[x][y])
		{
			used[tx][ty] = uc;
			qqx[j] = tx;
			qqy[j] = ty;
			j++;
		}
		tx = qqx[i]-1;
		ty = qqy[i];
		if (tx >= 0 && tx < n && ty >= 0 && ty < m && used[tx][ty] != uc && board[tx][ty] == board[x][y])
		{
			used[tx][ty] = uc;
			qqx[j] = tx;
			qqy[j] = ty;
			j++;
		}
	}
	return j;
}

void parse(char board[][W], int sort)
{
	int i, j, res, zn;
	uc++;
	rn = 0;
	zn = 0;
	for (i=n-1; i>=0; i--)
	{
		for (j=0; j<m; j++)
		{
			if (board[i][j] != 'A' && used[i][j] != uc)
			{
				int score = fill(board, i, j);
				if (score > 1)
				{
					resx[rn] = i;
					resy[rn] = j;
					resz[rn] = score;
					rs[rn] = rn;
					rn++;
				}
				else if (i > 0 && board[i-1][j] != 'A' && zn < T)
				{
					reszx[zn] = i;
					reszy[zn] = j;
					zn++;
				}
			}
		}
	}
	if (sort)
	{
		qsort(rs, rn, sizeof(rs[0]), comp2);
	}
	for (i=0; i<L&&i<zn; i++)
	{
		if (zn > (L<<2))
		{
			j = rand() % zn;
			while (reszx[j] < 0)
			{
				j = rand() % zn;
			}
		}
		else
		{
			j = i;
		}
		resx[rn] = reszx[j];
		resy[rn] = reszy[j];
		rn++;
		reszx[j] = -1;
	}
}

int erase(char board[][W], char board2[][W], int x, int y)
{
	int i, j, k, res;
	uc++;
	res = fill(board, x, y);
	for (j=0; j<m; j++)
	{
		for (i=n-1, k=n-1; i>=0; i--)
		{
			while (k>=0 && used[k][j] == uc)
			{
				k--;
			}
			if (k>=0)
			{
				board2[i][j] = board[k][j];
				k--;
			}
			else
			{
				for (; i>=0; i--)
				{
					board2[i][j] = 'A';
				}
				break;
			}
		}
	}
	return res;
}

int calc(char board[][W], int step)
{
	int i, j, res;
	uc++;
	scn = 0;
	for (i=0; i<n; i++)
	{
		for (j=0; j<m; j++)
		{
			if (board[i][j] != 'A' && used[i][j] != uc)
			{
				sc[scn++] = fill(board, i, j);
			}
		}
	}
	qsort(sc, scn, sizeof(int), comp);
	res = 0;
	for (i=0; i<step&&i<scn; i++)
	{
		res += sc[i];
	}
	return res;
}

void trace(int t)
{
	if (qt[t])
	{
		trace(qt[t]);
	}
	else
	{
		printf("%d\n", qd[best]);
	}
	/*decode(board, qb[t]);
	for (int i=0; i<n; i++)
	{
		printf("%s\n", board[i]);
	}
	printf("score: %d\n", qs[t]);*/
	printf("%d %d\n", qy[t]+1, qx[t]+1);
}

int main()
{
	int i, j, score, es;
	srand(TANE);
	scanf("%d%d%d", &m, &n, &o);
	for (i=0; i<n; i++)
	{
		scanf("%s", &qbb[0][i]);
	}
	//encode(board, qb[0]);
	qd[0] = 0;
	hn = 1;
	heap[1] = 0;
	dn = 1;
	ans = 0;
	best = 0;
	while (hn>=1)
	{
		i = heap[1];
		heap[1] = heap[hn--];
		heapdown(1);
		board = &qbb[i];
		if (qd[i] < o)
		{
			parse(*board, 0);
			for (j=0; j<rn&&dn<M&&hn<M; j++)
			{
				board2 = &qbb[dn];
				es = erase(*board, *board2, resx[j], resy[j]);
				score = calc(*board2, o-qd[i]);
				qx[dn] = resx[j];
				qy[dn] = resy[j];
				qs[dn] = score+es+qs[i];
				qd[dn] = qd[i]+1;
				qt[dn] = i;
				hn++;
				heap[hn] = dn;
				dn++;
				heapup(hn);
			}
		}
		if (qd[i] && qs[i] > ans)
		{
			ans = qs[i];
			best = i;
		}
	}
	if (best)
	{
		i = best;
		j = 0;
		while (qd[best] < o)
		{
			board = &qbb[i];
			parse(*board, 1);
			if (rn == 0)
			{
				break;
			}
			dn = (dn+1) % M;
			erase(*board, qbb[dn], resx[rs[0]], resy[rs[0]]);
			adx[j] = resx[rs[0]];
			ady[j] = resy[rs[0]];
			j++;
			i = dn;
			qd[best]++;
		}
		trace(best);
		for (i=0; i<j; i++)
		{
			printf("%d %d\n", ady[i]+1, adx[i]+1);
		}
	}
	else
	{
		printf("0\n");
	}
	return 0;
}
