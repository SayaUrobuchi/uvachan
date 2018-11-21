#include <stdio.h>

char s[1024];
int p[2][10005], *pn[2], *qn[2];
int idd[2][10005], *ppn[2], *qqn[2];
int ttt[10005];

int main()
{
	int count, n, i, lim, tim, fune, t, r, id;
	scanf("%d", &count);
	while (count--)
	{
		scanf("%d%d%d", &lim, &tim, &n);
		pn[0] = p[0];
		pn[1] = p[1];
		ppn[0] = idd[0];
		ppn[1] = idd[1];
		for (i=0; i<n; i++)
		{
			scanf("%d%s", &r, s);
			id = (*s == 'l' ? 0 : 1);
			*(pn[id]++) = r;
			*(ppn[id]++) = i;
		}
		fune = 0;
		t = 0;
		qn[0] = p[0];
		qn[1] = p[1];
		qqn[0] = idd[0];
		qqn[1] = idd[1];
		while (qn[0] < pn[0] || qn[1] < pn[1])
		{
			/* car exists */
			if (qn[fune] < pn[fune] && *qn[fune] <= t)
			{
				for (i=0; i<lim&&qn[fune]<pn[fune]&&*qn[fune]<=t; i++, qn[fune]++, qqn[fune]++)
				{
					ttt[*qqn[fune]] = tim+t;
				}
				t += tim;
				fune = 1-fune;
			}
			/* find next car to decide go opposide or wait */
			else
			{
				/* go opposide */
				if (qn[fune] >= pn[fune] || (qn[1-fune] < pn[1-fune] && *qn[1-fune] < *qn[fune]))
				{
					t = (t<*qn[1-fune] ? *qn[1-fune] : t) + tim;
					fune = 1-fune;
				}
				/* wait until next */
				else
				{
					t = *qn[fune];
				}
			}
		}
		for (i=0; i<n; i++)
		{
			printf("%d\n", ttt[i]);
		}
		if (count)
		{
			puts("");
		}
	}
	return 0;
}
