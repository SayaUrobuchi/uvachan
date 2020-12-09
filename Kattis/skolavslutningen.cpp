#include <iostream>

int par[32];
char buf[2][1048576];

int getpar(int now)
{
	if (par[now] == now)
	{
		return now;
	}
	return par[now] = getpar(par[now]);
}

int main()
{
	int n, m, o, i, j, a, b, ans;
	char *p, *q;
	while (scanf("%d%d%d", &n, &m, &o) == 3)
	{
		for (i=0; i<o; i++)
		{
			par[i] = i;
		}
		p = buf[0];
		q = buf[1];
		scanf("%s", p);
		for (i=1, ans=o; i<n; i++)
		{
			scanf("%s", q);
			for (j=0; j<m; j++)
			{
				a = getpar(p[j]-'A');
				b = getpar(q[j]-'A');
				if (a != b)
				{
					par[a] = b;
					--ans;
				}
			}
			std::swap(p, q);
		}
		printf("%d\n", ans);
	}
	return 0;
}
