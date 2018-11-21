#include <stdio.h>
#include <string.h>

#define M 10009

int ary[32][128][128];
int mata[128], matb[128];
int *pp, *qq, *tt;

int main()
{
	int n, m, i, j, k, p, q, d;
	while (scanf("%d%d%d%d", &n, &p, &q, &m) == 4)
	{
		for (i=0; i<n; i++)
		{
			for (j=0; j<n; j++)
			{
				scanf("%d", &ary[0][i][j]);
			}
		}
		memset(mata, 0, sizeof(mata));
		pp = mata;
		qq = matb;
		pp[p] = 1;
		for (d=0; m; d++, m>>=1)
		{
			if (m&1)
			{
				for (i=0; i<n; i++)
				{
					qq[i] = 0;
					for (j=0; j<n; j++)
					{
						qq[i] = (qq[i] + pp[j] * ary[d][j][i])%M;
					}
				}
				tt = pp;
				pp = qq;
				qq = tt;
			}
			for (i=0; i<n; i++)
			{
				for (j=0; j<n; j++)
				{
					ary[d+1][i][j] = 0;
					for (k=0; k<n; k++)
					{
						ary[d+1][i][j] = (ary[d+1][i][j] + ary[d][i][k] * ary[d][k][j])%M;
					}
				}
			}
		}
		printf("%d\n", pp[q]);
	}
	return 0;
}
