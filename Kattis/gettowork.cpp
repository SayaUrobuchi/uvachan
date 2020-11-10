#include <iostream>
#include <cstring>

int car[1024][8], pp[1024], jg[1024];

int main()
{
	int count, cas, n, m, o, i, j, p, q;
	bool gg;
	cas = 0;
	scanf("%d", &count);
	while (count--)
	{
		scanf("%d%d%d", &n, &m, &o);
		memset(car, 0, sizeof(car));
		memset(pp, 0, sizeof(pp));
		memset(jg, 0, sizeof(jg));
		for (i=0; i<o; i++)
		{
			scanf("%d%d", &p, &q);
			if (p != m)
			{
				++pp[p];
				jg[p] += 1-q;
				++car[p][q];
			}
		}
		for (i=1, gg=false; i<=n; i++)
		{
			if (jg[i] > 0)
			{
				gg = true;
				break;
			}
		}
		printf("Case #%d:", ++cas);
		if (gg)
		{
			puts(" IMPOSSIBLE");
		}
		else
		{
			for (i=1; i<=n; i++)
			{
				for (j=6, p=pp[i], q=0; j>=1&&p>0; j--)
				{
					for (; car[i][j]&&p>0; --car[i][j], p-=j, ++q);
				}
				printf(" %d", q);
			}
			puts("");
		}
	}
	return 0;
}
