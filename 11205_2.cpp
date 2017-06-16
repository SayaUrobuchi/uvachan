#include <stdio.h>

int used[65536], cused[65536], tbl[128][16], q[65536], qs[65536];

int main()
{
	int count, n, m, i, j, k, l, cnt, uc, now, nxt, h;
	cnt = uc = 0;
	scanf("%d", &count);
	while (count--)
	{
		scanf("%d%d", &n, &m);
		for (i=0; i<m; i++)
		{
			for (j=0; j<n; j++)
			{
				scanf("%d", &tbl[i][j]);
			}
		}
		++cnt;
		used[0] = cnt;
		q[0] = 0;
		qs[0] = 0;
		for (i=0, j=1; i<j; i++)
		{
			now = q[i];
			uc++;
			for (k=0; k<m; k++)
			{
				h = 0;
				for (l=0; l<n; l++)
				{
					if ((now & (1<<l)) && tbl[k][l])
					{
						h += (1<<l);
					}
				}
				if (cused[h] == uc)
				{
					break;
				}
				cused[h] = uc;
			}
			if (k >= m)
			{
				break;
			}
			for (k=0; k<n; k++)
			{
				nxt = now | (1<<k);
				if (used[nxt] != cnt)
				{
					used[nxt] = cnt;
					q[j] = nxt;
					qs[j] = qs[i]+1;
					j++;
				}
			}
		}
		printf("%d\n", qs[i]);
	}
	return 0;
}
