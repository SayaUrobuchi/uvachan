#include <stdio.h>
#include <algorithm>

#define M 65536
#define SS 32768

int used[M];
int ary[M];
int bry[M];
int pn, qn;
int *p, *q, *tt;

int main()
{
	int n, m, i, j, k, t, cnt, l, r, c, res;
	cnt = 0;
	while (scanf("%d%d", &n, &m) == 2)
	{
		++cnt;
		ary[0] = SS;
		used[SS] = cnt;
		p = ary;
		q = bry;
		pn = 1;
		qn = 0;
		for (i=0; i<n; i++)
		{
			scanf("%d", &t);
			++cnt;
			for (j=0; j<pn; j++)
			{
				k = p[j]+t;
				if (used[k] != cnt)
				{
					used[k] = cnt;
					q[qn++] = k;
				}
				k = p[j]-t;
				if (used[k] != cnt)
				{
					used[k] = cnt;
					q[qn++] = k;
				}
			}
			tt = p;
			p = q;
			q = tt;
			pn = qn;
			qn = 0;
		}
		std::sort(p, p+pn);
		while (m--)
		{
			scanf("%d", &t);
			t += SS;
			if (used[t] == cnt)
			{
				printf("%d\n", t-SS);
			}
			else
			{
				for (l=0, r=pn-1, res=p[0]; l<=r; )
				{
					c = ((l+r) >> 1);
					if (p[c] < t)
					{
						l = c+1;
					}
					else
					{
						r = c-1;
						res = p[c];
					}
				}
				printf("%d\n", res-SS);
			}
		}
	}
	return 0;
}
