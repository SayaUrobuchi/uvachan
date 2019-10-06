#include <stdio.h>
#include <algorithm>

const int END_STAT = ((7<<21) | (6<<18) | (5<<15) | (4<<12) | (3<<9) | (2<<6) | (1<<3));
const int N = 8;
const int N2 = 3;
const int QN = 65536;

int ary[N];
int mask[N][N], mask3[N][N];
int tbl[N+N];
int mat[N][N];
int used[1<<24], ucnt;
int qq[QN], qs[QN], qx[QN];

int diff(int stat, int p, int q)
{
	return ((stat & (1<<p))>>p) ^ ((stat & (1<<q))>>q);
}

int is_mat(int stat, int p, int q)
{
	p = ((stat & (7<<(p*N2))) >> (p*N2));
	q = ((stat & (7<<(q*N2))) >> (q*N2));
	return mat[p][q];
}

int move(int stat, int type, int p, int q)
{
	int (*msk)[N] = (type == N2 ? mask3 : mask);
	int res = (stat & (~msk[p][q]));
	if (p < q)
	{
		res |= ((stat & msk[p+1][q])>>type) | ((stat & msk[p][p])<<((q-p)*type));
	}
	else
	{
		res |= ((stat & msk[p-1][q])<<type) | ((stat & msk[p][p])>>((p-q)*type));
	}
	return res;
}

void pp(int p, int q)
{
	int i;
	printf("(");
	for (i=0; i<8; i++, p>>=N2)
	{
		printf("%d", (p&7)+1);
	}
	printf(") => (");
	for (i=0; i<8; i++, q>>=N2)
	{
		printf("%d", (q&7)+1);
	}
	puts(")");
}

int main()
{
	int cas, i, j, k, l, stat, sex, step, nxt, p, q;
	cas = 0;
	tbl[2] = tbl[3] = tbl[5] = tbl[7] = tbl[11] = tbl[13] = 1;
	for (i=0; i<N; i++)
	{
		mask[i][i] = (1 << (i));
		mask3[i][i] = (7 << (i*N2));
		for (j=i+1; j<N; j++)
		{
			if (tbl[i+j+2])
			{
				mat[i][j] = mat[j][i] = 1;
			}
		}
	}
	for (i=1; i<N; i++)
	{
		for (j=0, k=j+i; k<N; j++, k++)
		{
			mask[j][k] = mask[k][j] = (mask[j][k-1] | (1 << (k)));
			mask3[j][k] = mask3[k][j] = (mask3[j][k-1] | (7 << (k*N2)));
		}
	}
	while (scanf("%d", &ary[0]) == 1)
	{
		if (!*ary)
		{
			break;
		}
		for (i=1; i<N; i++)
		{
			scanf("%d", &ary[i]);
		}
		for (i=0, stat=0, sex=0; i<N; i++)
		{
			stat |= ((std::abs(ary[i])-1) << (N2*i));
			sex |= ((ary[i]>0 ? 0 : 1) << i);
		}
		qq[0] = stat;
		qs[0] = 0;
		qx[0] = sex;
		ucnt++;
		used[stat] = ucnt;
		for (i=0, j=1; i<j; i++)
		{
			if (qq[i] == END_STAT)
			{
				break;
			}
			stat = qq[i];
			step = qs[i];
			sex = qx[i];
			for (k=0; k<N; k++)
			{
				for (l=0; l<N; l++)
				{
					if (k != l)
					{
						// move k to l
						if (k > l)
						{
							p = l-1;
							q = l;
						}
						else
						{
							p = l;
							q = l+1;
						}
						if ((p>=0 && diff(sex, p, k) && is_mat(stat, p, k)) || (q<N && diff(sex, q, k) && is_mat(stat, q, k)))
						{
							nxt = move(stat, N2, k, l);
							if (used[nxt] != ucnt)
							{
								//pp(stat, nxt);
								used[nxt] = ucnt;
								qq[j] = nxt;
								qs[j] = step+1;
								qx[j] = move(sex, 1, k, l);
								j++;
							}
						}
					}
				}
			}
		}
		printf("Case %d: %d\n", ++cas, i>=j?-1:qs[i]);
	}
	return 0;
}
