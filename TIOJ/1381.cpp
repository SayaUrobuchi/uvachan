#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int num[55], map[55][55], list[55], n, m, c, pn, ans, now;
char used[55], used2[55], sel[55];
long long bit[55];

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
	if(p == pn)
	{
		c = nod;
		return;
	}
	q = list[p];
	if((state & bit[q]) || used[q])
	{
		dfs(p+1, nod, state);
	}
	else
	{
		if(!used[q] && (pn < 3 || num[q] != 1))
		{
			used[q] = 1;
			dfs(p+1, nod+1, state|(1ll<<q));
			used[q] = 0;
		}
		for(i=0; i<num[q]; i++)
		{
			if(used[map[q][i]] == 0)
			{
				used[map[q][i]] = 1;
				dfs(p+1, nod+1, state|(1ll<<map[q][i]));
				used[map[q][i]] = 0;
			}
		}
	}
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
			bit[i] = 0;
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
				c = 0;
				for(j=0; j<pn; j++)
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
