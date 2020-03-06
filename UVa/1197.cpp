#include <stdio.h>
#include <string.h>

const int N = 32768;
const int M = 512;

int par[N], num[N];

int getpar(int p)
{
	if (par[p] < 0)
	{
		return p;
	}
	return par[p] = getpar(par[p]);
}

int main()
{
	int n, m, i, j, t, p, q;
	while (scanf("%d%d", &n, &m) == 2)
	{
		if (n == 0 && m == 0)
		{
			break;
		}
		memset(par, -1, sizeof(par));
		memset(num, -1, sizeof(num));
		for (i=0; i<m; i++)
		{
			scanf("%d", &t);
			if (t)
			{
				scanf("%d", &p);
				p = getpar(p);
				for (j=1; j<t; j++)
				{
					scanf("%d", &q);
					q = getpar(q);
					if (p != q)
					{
						par[q] = p;
						num[p] += num[q];
					}
				}
			}
		}
		printf("%d\n", -num[getpar(0)]);
	}
	return 0;
}
