#include <stdio.h>

#define N 65536

int map[N], dfn[N], len[N], stk[N], sn;

int main()
{
	int cas, count, n, i, j, p, q, cc, mx, mp, now, nxt, d;
	scanf("%d", &count);
	cas = 0;
	while (count--)
	{
		scanf("%d", &n);
		for (i=1; i<=n; i++)
		{
			scanf("%d%d", &p, &q);
			map[p] = q;
			dfn[i] = 0;
			len[i] = 0;
		}
		cc = 0;
		mx = 0;
		mp = -1;
		for (i=1; i<=n; i++)
		{
			if (!dfn[i])
			{
				stk[0] = i;
				sn = 1;
				now = i;
				for (j=0; j<sn; j++)
				{
					nxt = map[now];
					dfn[now] = ++cc;
					if (dfn[nxt])
					{
						if (!len[nxt])
						{
							d = cc-dfn[nxt]+1;
							while (now != nxt)
							{
								now = stk[--sn];
								len[now] = d;
							}
						}
						break;
					}
					stk[sn++] = nxt;
					now = nxt;
				}
				while (sn--)
				{
					now = stk[sn];
					len[now] = len[map[now]]+1;
				}
				if (len[i] > mx)
				{
					mx = len[i];
					mp = i;
				}
			}
		}
		printf("Case %d: %d\n", ++cas, mp);
	}
	return 0;
}
