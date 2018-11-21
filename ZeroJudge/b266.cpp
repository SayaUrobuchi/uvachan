#include <stdio.h>

#define N 1024

int mat[N][N], matt[N][N], ary[N];

int main()
{
	int n, m, o, i, j, k, r;
	int (*p)[N], (*q)[N], (*t)[N];
	n = 2;
	m = 2;
	n ^= m ^= n ^= m;
	while (scanf("%d%d%d", &n, &m, &o) == 3)
	{
		for (i=0; i<n; i++)
		{
			for (j=0; j<m; j++)
			{
				scanf("%d", &mat[i][j]);
			}
		}
		p = mat;
		q = matt;
		for (i=0; i<o; i++)
		{
			scanf("%d", &ary[i]);
		}
		for (k=o-1; k>=0; k--)
		{
			if (!ary[k])
			{
				for (i=0; i<m; i++)
				{
					for (j=0; j<n; j++)
					{
						q[i][j] = p[j][m-i-1];
					}
				}
				n ^= m ^= n ^= m;
				t = p;
				p = q;
				q = t;
			}
			else
			{
				for (i=0; i+i+1<n; i++)
				{
					for (j=0; j<m; j++)
					{
						p[i][j] ^= p[n-i-1][j] ^= p[i][j] ^= p[n-i-1][j];
					}
				}
			}
		}
		printf("%d %d\n", n, m);
		for (i=0; i<n; i++)
		{
			printf("%d", p[i][0]);
			for (j=1; j<m; j++)
			{
				printf(" %d", p[i][j]);
			}
			puts("");
		}
	}
	return 0;
}
