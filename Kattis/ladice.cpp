#include <iostream>
#include <cstring>

int par[1048576], rnk[1048576];
int cnt[1048576];

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
		memset(par, -1, sizeof(par));
		memset(rnk, -1, sizeof(rnk));
		memset(cnt, -1, sizeof(cnt));
		for (i=0; i<n; i++)
		{
			scanf("%d%d", &a, &b);
			a = getpar(a);
			b = getpar(b);
			if (a != b)
			{
				if (rnk[a] > rnk[b])
				{
					par[a] = b;
					cnt[b] += cnt[a];
					std::swap(a, b);
				}
				else
				{
					par[b] = a;
					cnt[a] += cnt[b];
					if (rnk[a] == rnk[b])
					{
						--rnk[a];
					}
				}
			}
			if (cnt[a] != 0)
			{
				puts("LADICA");
				++cnt[a];
			}
			else
			{
				puts("SMECE");
			}
		}
	}
	return 0;
}
