#include <stdio.h>

int pos[1000005], nxt[128];

int main()
{
	int count, n, m, o, p, q, i;
	scanf("%d", &count);
	while (count--)
	{
		scanf("%d%d%d", &n, &m, &o);
		for (i=1; i<=n; i++)
		{
			pos[i] = 1;
		}
		for (i=1; i<=100; i++)
		{
			nxt[i] = i;
		}
		for (; i<=105; i++)
		{
			nxt[i] = 100;
		}
		for (i=0; i<m; i++)
		{
			scanf("%d%d", &p, &q);
			nxt[p] = q;
		}
		p = 1;
		while (o--)
		{
			scanf("%d", &q);
			pos[p] += q;
			pos[p] = nxt[pos[p]];
			if (pos[p] >= 100)
			{
				pos[p] = 100;
				while (o--)
				{
					scanf("%*d");
				}
				break;
			}
			++p;
			if (p > n)
			{
				p = 1;
			}
		}
		for (i=1; i<=n; i++)
		{
			printf("Position of player %d is %d.\n", i, pos[i]);
		}
	}
	return 0;
}
