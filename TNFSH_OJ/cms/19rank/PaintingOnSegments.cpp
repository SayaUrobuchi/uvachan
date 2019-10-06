#include <stdio.h>

int ary[1048576];
int sn, stk[1048576], stkc[1048576];

int main()
{
	int n, m, i, t, p, q;
	while (scanf("%d", &n) == 1)
	{
		for (i=0; i<n; i++)
		{
			scanf("%d", &ary[i]);
		}
		scanf("%d", &m);
		sn = -1;
		for (i=0; i<m; i++)
		{
			scanf("%d%d", &p, &q);
			--p;
			for (; sn>=0&&p>=stk[sn]; sn--);
			++sn;
			stk[sn] = p;
			stkc[sn] = q;
		}
		for (i=0; i<n; i++)
		{
			t = ary[i];
			if (sn >= 0)
			{
				t = stkc[sn];
				if (stk[sn] == i)
				{
					--sn;
				}
			}
			printf(i?" %d":"%d", t);
		}
		puts("");
	}
	return 0;
}
