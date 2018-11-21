#include <stdio.h>
#include <string.h>

int board[32][32][2];
int ary0[131072], ary1[131072];

int main()
{
	int n, M, i, j, k, l, p, q, r, t, mask, ans;
	int *cur, *nxt, *temp;
	while (scanf("%d%d", &n, &M) == 2)
	{
		for (i=0; i<n; i++)
		{
			for (j=0; j<n; j++)
			{
				scanf("%d%d", &board[i][j][0], &board[i][j][1]);
			}
		}
		mask = (1 << n) - 1;
		cur = ary0;
		nxt = ary1;
		for (k=0; k<=mask; k++)
		{
			for (i=1, j=n-2; i<n; i++, j--)
			{
				p = ((k & (1<<(j+1))) ? 1 : 0);
				q = ((k & (1<<j)) ? 1 : 0);
				if (board[0][i-1][p] == board[0][i][q])
				{
					break;
				}
			}
			cur[k] = (i < n ? 0 : 1) % M;
		}
		for (i=1; i<n; i++)
		{
			for (j=0; j<n; j++)
			{
				memset(nxt, 0, sizeof(ary0));
				for (k=0; k<=mask; k++)
				{
					if (cur[k])
					{
						p = (j ? board[i][j-1][k&1] : -1);
						q = board[i-1][j][k>>(n-1)];
						for (l=0; l<2; l++)
						{
							r = board[i][j][l];
							if (r != p && r != q)
							{
								t = ((k<<1)&mask)+l;
								nxt[t] = (nxt[t]+cur[k]) % M;
							}
						}
					}
				}
				temp = nxt;
				nxt = cur;
				cur = temp;
			}
		}
		for (k=0, ans=0; k<=mask; k++)
		{
			ans = (ans+cur[k]) % M;
		}
		printf("%d\n", ans);
	}
	return 0;
}
