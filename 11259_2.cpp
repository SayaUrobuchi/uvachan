#include <stdio.h>
#include <string.h>

int cnt;
int ary[4], num[4];
int tbl[2][100005], s[100005], used[100005];

int main()
{
	int count, n, m, i, j, k, a, c, t, now;
	int *p, *q, *r;
	scanf("%d", &count);
	while (count--)
	{
		scanf("%d%d%d%d%d", &ary[0], &ary[1], &ary[2], &ary[3], &m);
		while (m--)
		{
			scanf("%d%d%d%d%d", &num[0], &num[1], &num[2], &num[3], &n);
			memset(tbl, 0, sizeof(tbl));
			p = tbl[0];
			q = tbl[1];
			p[0] = 1;
			for (i=0; i<4; i++)
			{
				t = num[i];
				++cnt;
				for (j=0; (1<<j)<=t; j++)
				{
					c = (1<<j);
					t -= c;
					now = ary[i] * c;
					for (k=n; k>=now; k--)
					{
						if (used[k] != cnt)
						{
							q[k] = 0;
							used[k] = cnt;
						}
						q[k] += p[k-now]+q[k-now];
					}
				}
				if (t)
				{
					a = (1<<j)-1;
					while (t)
					{
						c = a;
						now = ary[i]*c;
						if (now > n)
						{
							break;
						}
						for (k=n; k>=now; k--)
						{
							s[k] = p[k-now];
						}
						for (k=now-1; k>=0; k--)
						{
							s[k] = 0;
						}
						for (j=0; (1<<j)<=t; j++)
						{
							c = (1<<j);
							t -= c;
							now = ary[i] * c;
							for (k=n; k>=now; k--)
							{
								s[k] += s[k-now];
							}
						}
						c = a;
						now = ary[i]*c;
						for (k=n; k>=now; k--)
						{
							s[k] -= p[k-now];
						}
						for (k=0; k<=n; k++)
						{
							q[k] += s[k];
						}
						a += (1<<j)-1;
					}
				}
				for (k=0; k<=n; k++)
				{
					q[k] += p[k];
				}
				r = p;
				p = q;
				q = r;
			}
			printf("%d\n", p[n]);
		}
	}
	return 0;
}
