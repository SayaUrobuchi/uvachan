#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int alis[1000001][4], ptt[1000001], ary[1005][1005], row[1005][1005];

int comp(int *p, int *q)
{
	int i;
	for(i=0; i<4; i++)
	{
		if(p[i] != q[i])
		{
			return p[i] - q[i];
		}
	}
	return 0;
}

int ali_comp(const void *p, const void *q)
{
	return comp(alis[*(int*)p], alis[*(int*)q]);
}

int calc(int p, int q, int r, int s)
{
	return row[p+r-1][q+s-1] - row[p-1][q+s-1] - row[p+r-1][q-1] + row[p-1][q-1];
}

int main()
{
	int n, m, i, j, k, p, q, sq, acnt, ans, x, y;
	while(scanf("%d%d%d", &n, &m, &k) == 3)
	{
		for(i=1; i<=n; i++)
		{
			for(j=1; j<=m; j++)
			{
				scanf("%d", &ary[i][j]);
				row[i][j] = row[i][j-1] + row[i-1][j] - row[i-1][j-1] + ary[i][j];
			}
		}
		sq = (int)(sqrt(k)+1e-10);
		for(i=1, acnt=0, ans=2147483647; i<=sq; i++)
		{
			if(k % i == 0)
			{
				p = i;
				q = k/i;
				if(q <= m)
				{
					for(x=1, y=1; x+p<=n+1; x++)
					{
						if(q < m || (x == 1 || x+p==n+1))
						{
							if(calc(x, y, p, q) < ans)
							{
								ans = calc(x, y, p, q);
								acnt = 1;
								alis[0][0] = x;
								alis[0][2] = y;
								alis[0][1] = x+p-1;
								alis[0][3] = y+q-1;
							}
							else if(calc(x, y, p, q) == ans)
							{
								alis[acnt][0] = x;
								alis[acnt][2] = y;
								alis[acnt][1] = x+p-1;
								alis[acnt][3] = y+q-1;
								acnt++;
							}
							if(calc(x, m-q+1, p, q) < ans)
							{
								ans = calc(x, m-q+1, p, q);
								acnt = 1;
								alis[0][0] = x;
								alis[0][2] = m-q+1;
								alis[0][1] = x+p-1;
								alis[0][3] = m;
							}
							else if(calc(x, m-q+1, p, q) == ans)
							{
								alis[acnt][0] = x;
								alis[acnt][2] = m-q+1;
								alis[acnt][1] = x+p-1;
								alis[acnt][3] = m;
								acnt++;
							}
						}
					}
				}
				if(p <= n)
				{
					for(x=1, y=1; y+q<=m+1; y++)
					{
						if(p < n || (y == 1 || y+q==m+1))
						{
							if(calc(x, y, p, q) < ans)
							{
								ans = calc(x, y, p, q);
								acnt = 1;
								alis[0][0] = x;
								alis[0][2] = y;
								alis[0][1] = x+p-1;
								alis[0][3] = y+q-1;
							}
							else if(calc(x, y, p, q) == ans)
							{
								alis[acnt][0] = x;
								alis[acnt][2] = y;
								alis[acnt][1] = x+p-1;
								alis[acnt][3] = y+q-1;
								acnt++;
							}
							if(calc(n-p+1, y, p, q) < ans)
							{
								ans = calc(n-p+1, y, p, q);
								acnt = 1;
								alis[0][0] = n-p+1;
								alis[0][2] = y;
								alis[0][1] = n;
								alis[0][3] = y+q-1;
							}
							else if(calc(n-p+1, y, p, q) == ans)
							{
								alis[acnt][0] = n-p+1;
								alis[acnt][2] = y;
								alis[acnt][1] = n;
								alis[acnt][3] = y+q-1;
								acnt++;
							}
						}
					}
				}
				p = k/i;
				q = i;
				if(q <= m)
				{
					for(x=1, y=1; x+p<=n+1; x++)
					{
						if(q < m || (x == 1 || x+p==n+1))
						{
							if(calc(x, y, p, q) < ans)
							{
								ans = calc(x, y, p, q);
								acnt = 1;
								alis[0][0] = x;
								alis[0][2] = y;
								alis[0][1] = x+p-1;
								alis[0][3] = y+q-1;
							}
							else if(calc(x, y, p, q) == ans)
							{
								alis[acnt][0] = x;
								alis[acnt][2] = y;
								alis[acnt][1] = x+p-1;
								alis[acnt][3] = y+q-1;
								acnt++;
							}
							if(calc(x, m-q+1, p, q) < ans)
							{
								ans = calc(x, m-q+1, p, q);
								acnt = 1;
								alis[0][0] = x;
								alis[0][2] = m-q+1;
								alis[0][1] = x+p-1;
								alis[0][3] = m;
							}
							else if(calc(x, m-q+1, p, q) == ans)
							{
								alis[acnt][0] = x;
								alis[acnt][2] = m-q+1;
								alis[acnt][1] = x+p-1;
								alis[acnt][3] = m;
								acnt++;
							}
						}
					}
				}
				if(p <= n)
				{
					for(x=1, y=1; y+q<=m+1; y++)
					{
						if(p < n || (y == 1 || y+q==m+1))
						{
							if(calc(x, y, p, q) < ans)
							{
								ans = calc(x, y, p, q);
								acnt = 1;
								alis[0][0] = x;
								alis[0][2] = y;
								alis[0][1] = x+p-1;
								alis[0][3] = y+q-1;
							}
							else if(calc(x, y, p, q) == ans)
							{
								alis[acnt][0] = x;
								alis[acnt][2] = y;
								alis[acnt][1] = x+p-1;
								alis[acnt][3] = y+q-1;
								acnt++;
							}
							if(calc(n-p+1, y, p, q) < ans)
							{
								ans = calc(n-p+1, y, p, q);
								acnt = 1;
								alis[0][0] = n-p+1;
								alis[0][2] = y;
								alis[0][1] = n;
								alis[0][3] = y+q-1;
							}
							else if(calc(n-p+1, y, p, q) == ans)
							{
								alis[acnt][0] = n-p+1;
								alis[acnt][2] = y;
								alis[acnt][1] = n;
								alis[acnt][3] = y+q-1;
								acnt++;
							}
						}
					}
				}
			}
		}
		for(i=0; i<acnt; i++)
		{
			ptt[i] = i;
		}
		qsort(ptt, acnt, sizeof(int), ali_comp);
		for(i=0, p=0; i<acnt; )
		{
			for(j=i+1; j<acnt; j++)
			{
				if(comp(alis[ptt[i]], alis[ptt[j]]))
				{
					break;
				}
			}
			ptt[p++] = ptt[i];
			i = j;
		}
		printf("%d %d\n", ans, p);
		for(i=0; i<p; i++)
		{
			printf("%d %d %d %d\n", alis[ptt[i]][0], alis[ptt[i]][1], alis[ptt[i]][2], alis[ptt[i]][3]);
		}
	}
	return 0;
}
