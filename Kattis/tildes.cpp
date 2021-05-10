#include <iostream>

int par[1048576], siz[1048576];
char s[1024];

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
	int n, m, i, a, b;
	while (scanf("%d%d", &n, &m) == 2)
	{
		for (i=1; i<=n; i++)
		{
			par[i] = -1;
			siz[i] = 1;
		}
		for (i=0; i<m; i++)
		{
			scanf("%s", s);
			if (*s == 't')
			{
				scanf("%d%d", &a, &b);
				a = getpar(a);
				b = getpar(b);
				if (a != b)
				{
					par[a] = b;
					siz[b] += siz[a];
				}
			}
			else
			{
				scanf("%d", &a);
				a = getpar(a);
				printf("%d\n", siz[a]);
			}
		}
	}
	return 0;
}