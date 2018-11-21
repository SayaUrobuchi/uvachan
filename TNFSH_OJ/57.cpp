#include <stdio.h>
#include <string.h>

#define M 433494437
#define N 4
#define NN 108

int ary[N], real[NN];
long long r0[NN][NN], t0[NN][NN], t1[NN][NN], st[NN];
long long (*res)[NN], (*trans)[NN], (*t)[NN], (*tt)[NN];

int main()
{
	int i, j, k, n, m, o, r, p, q, ans;
	while (scanf("%d%d%d", &n, &m, &o) == 3)
	{
		if (n < m)
		{
			n ^= m ^= n ^= m;
		}
		for (i=0, r=1; i<m; i++, r*=o);
		for (i=0, q=0; i<r; i++)
		{
			p = i;
			for (j=0; j<m; j++, p/=o)
			{
				ary[j] = p%o;
			}
			for (j=0; j<m; j++)
			{
				if (!((j<1 || ary[j]!=ary[j-1]) && (j+1>=m || ary[j]!=ary[j+1])))
				{
					break;
				}
			}
			if (j >= m)
			{
				real[q++] = i;
			}
			st[i] = i;
		}
		r = q;
		trans = t0;
		memset(trans, 0, sizeof(t0));
		res = r0;
		memset(res, 0, sizeof(r0));
		t = t1;
		for (i=0; i<r; i++)
		{
			for (j=0; j<r; j++)
			{
				for (k=0, p=real[i], q=real[j]; k<m&&p%o!=q%o; k++, p/=o, q/=o);
				if (k >= m)
				{
					trans[i][j] = 1;
				}
			}
			res[i][i] = 1;
		}
		--n;
		while (n)
		{
			if (n & 1)
			{
				for (i=0; i<r; i++)
				{
					for (j=0; j<r; j++)
					{
						t[i][j] = 0;
						for (k=0; k<r; k++)
						{
							t[i][j] += (res[i][k]*trans[k][j]) % M;
						}
						t[i][j] %= M;
					}
				}
				tt = res;
				res = t;
				t = tt;
			}
			for (i=0; i<r; i++)
			{
				for (j=0; j<r; j++)
				{
					t[i][j] = 0;
					for (k=0; k<r; k++)
					{
						t[i][j] += (trans[i][k]*trans[k][j]) % M;
					}
					t[i][j] %= M;
				}
			}
			tt = trans;
			trans = t;
			t = tt;
			n >>= 1;
		}
		ans = 0;
		for (i=0; i<r; i++)
		{
			for (j=0; j<r; j++)
			{
				ans = (ans+res[j][i]) % M;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
