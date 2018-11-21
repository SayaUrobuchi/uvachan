#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int num[55], map[55][55], list[55], n, m, c, pn, ans, now;
char used[55], used2[55], sel[55];
long long bit[55], cover[55], f;

int comp(const void *p, const void *q)
{
	return num[*(int*)q] - num[*(int*)p];
}

void count(int p)
{
	int i;
	used2[p] = 1;
	list[pn++] = p;
	for(i=0; i<num[p]; i++)
	{
		if(used2[map[p][i]] == 0)
		{
			count(map[p][i]);
		}
	}
}

void dfs(int p, int nod, long long state)
{
	int i, q;
	if(nod >= c)
	{
		return;
	}
	if(state == f)
	{
		c = nod;
		return;
	}
	if(p == pn)
	{
		return;
	}
	q = list[p];
	if((state | cover[q]) != f)
	{
		return;
	}
	if((state | bit[q]) != state)
	{
		dfs(p+1, nod+1, state|bit[q]);
	}
	dfs(p+1, nod, state);
}

int main()
{
	int i, j, k, p;
	while(scanf("%d%d", &n, &m) == 2)
	{
		if(n == 0)
		{
			break;
		}
		memset(map, 0, sizeof(map));
		while(m--)
		{
			scanf("%d%d", &i, &j);
			map[i][j] = map[j][i] = 1;
		}
		for(i=1; i<=n; i++)
		{
			num[i] = 0;
			bit[i] = (1ll << i);
			for(j=1; j<=n; j++)
			{
				if(map[i][j])
				{
					map[i][num[i]++] = j;
					bit[i] |= (1ll << j);
				}
			}
		}
		memset(used2, 0, sizeof(used2));
		memset(used, 0, sizeof(used));
		memset(sel, 0, sizeof(sel));
		for(i=1, ans=0; i<=n; i++)
		{
			if(used2[i] == 0)
			{
				pn = 0;
				count(i);
				if(pn < 4)
				{
					ans++;
					continue;
				}
				qsort(list, pn, sizeof(int), comp);
				cover[list[pn-1]] = bit[list[pn-1]];
				for(j=pn-2; j>=0; j--)
				{
					p = list[j];
					cover[p] = (cover[list[j+1]] | bit[p]);
				}
				c = 0;
				for(j=0, f=cover[list[0]]; j<pn; j++)
				{
					p = list[j];
					if(sel[p] == 0)
					{
						for(k=0; k<num[p]; k++)
						{
							if(sel[map[p][k]])
							{
								break;
							}
						}
						if(k < num[p])
						{
							continue;
						}
						sel[p] = 1;
						c++;
					}
				}
				dfs(0, 0, 0);
				ans += c;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
