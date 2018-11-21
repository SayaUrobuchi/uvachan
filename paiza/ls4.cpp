#include <stdio.h>
#include <stdlib.h>

#define M 30005
#define R 1024
#define T 7
#define L 7
#define W 52

char qbb[M][50][W];
int qs[M], qrs[M], qx[M], qy[M], qd[M], qt[M], dn;
char qresx[M][R], qresy[M][R];
short qresz[M][R], qres[M][R], qrn[M];
int adx[100], ady[100];
int heap[M], hn;
char (*board)[50][W], (*board2)[50][W];
int used[50][50], uc;
int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
int qqx[2505], qqy[2505];
unsigned int at[128], ta[4];
int reszx[T], reszy[T];
char *resx, *resy;
short *resz, *rs, rn;
int n, m, o, ans, best;

int comp(const void *p, const void *q)
{
	return *(int*)q - *(int*)p;
}

int comp2(const void *p, const void *q)
{
	return resz[*(short*)q]-resz[*(short*)p];
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
		for (k=0; k<4; k++)
		{
			tx = qqx[i]+dx[k];
			ty = qqy[i]+dy[k];
			if (tx >= 0 && tx < n && ty >= 0 && ty < m && used[tx][ty] != uc && board[tx][ty] == board[x][y])
			{
				used[tx][ty] = uc;
				qqx[j] = tx;
				qqy[j] = ty;
				j++;
			}
		}
	}
	return j;
}

int parse(char board[][W], int step, char resx[], char resy[], short gresz[], short rs[], short *rn)
{
	int i, j, res, zn;
	uc++;
	*rn = 0;
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
					resx[*rn] = i;
					resy[*rn] = j;
					gresz[*rn] = score;
					rs[*rn] = *rn;
					(*rn)++;
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
	resz = gresz;
	qsort(rs, *rn, sizeof(rs[0]), comp2);
	for (i=0; i<L&&i<zn; i++)
	{
		/*if (zn > (L<<1))
		{
			j = rand() % zn;
		}
		else
		{
			j = i;
		}*/
		j = i;
		resx[*rn] = reszx[j];
		resy[*rn] = reszy[j];
		rs[*rn] = *rn;
		(*rn)++;
	}
	for (i=0; i<step&&i<*rn; i++)
	{
		res += resz[rs[i]];
	}
	return res;
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
				board2[i][j] = 'A';
			}
		}
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
	at['A'] = 0;
	at['R'] = 1;
	at['G'] = 2;
	at['B'] = 3;
	ta[0] = 'A';
	ta[1] = 'R';
	ta[2] = 'G';
	ta[3] = 'B';
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
	parse(qbb[0], o, qresx[0], qresy[0], qresz[0], qres[0], &qrn[0]);
	while (hn>=1)
	{
		i = heap[1];
		heap[1] = heap[hn--];
		heapdown(1);
		board = &qbb[i];
		if (qd[i] < o)
		{
			rn = qrn[i];
			resx = qresx[i];
			resy = qresy[i];
			for (j=0; j<rn&&dn<M&&hn<M; j++)
			{
				board2 = &qbb[dn];
				es = erase(*board, *board2, resx[j], resy[j]);
				score = parse(*board2, o-qd[i], qresx[dn], qresy[dn], qresz[dn], qres[dn], &qrn[dn]);
				qx[dn] = resx[j];
				qy[dn] = resy[j];
				qs[dn] = score;
				qrs[dn] = qrs[i] + es;
				qd[dn] = qd[i]+1;
				qt[dn] = i;
				hn++;
				heap[hn] = dn;
				dn++;
				heapup(hn);
			}
		}
		if (qd[i] && qrs[i] > ans)
		{
			ans = qrs[i];
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
			rn = qrn[i];
			resx = qresx[i];
			resy = qresy[i];
			rs = qres[i];
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
			parse(qbb[dn], o-qd[best], qresx[dn], qresy[dn], qresz[dn], qres[dn], &qrn[dn]);
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
	//printf("1\n1 1\n");
	return 0;
}
