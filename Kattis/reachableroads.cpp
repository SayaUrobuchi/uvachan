#include <iostream>
#include <cstring>

int par[1024];

int getpar(int cur)
{
	if (par[cur] == -1)
	{
		return cur;
	}
	return par[cur] = getpar(par[cur]);
}

int main()
{
	int count, n, m, i, p, q, c;
	scanf("%d", &count);
	while (count--)
	{
		scanf("%d%d", &n, &m);
		memset(par, -1, sizeof(par));
		for (i=0, c=1; i<m; i++)
		{
			scanf("%d%d", &p, &q);
			if (getpar(p) != getpar(q))
			{
				++c;
				par[getpar(p)] = getpar(q);
			}
		}
		printf("%d\n", n-c);
	}
	return 0;
}
