#include <stdio.h>
#include <string.h>

int n, f, cnt;
int deg[205];
int used[205];
int map[205][205];
int con[205][205], cc[205];

void dfs(int now)
{
	int i, j;
	f += deg[now] & 1;
	if(f)
	{
		return;
	}
	for(i=0; i<cc[now]; i++)
	{
		j = con[now][i];
		if(used[j] != cnt)
		{
			used[j] = cnt;
			dfs(j);
			if(f)
			{
				return;
			}
		}
	}
}

int main()
{
	int m, i, p, q, r, s;
	cnt = 0;
	while(scanf("%d%d", &n, &m) == 2)
	{
		++cnt;
		memset(deg, 0, sizeof(deg));
		memset(cc, 0, sizeof(cc));
		s = m;
		while(m--)
		{
			scanf("%d%d", &p, &q);
			if (map[p][q] != cnt)
			{
				map[q][p] = map[p][q] = cnt;
				con[q][cc[q]++] = p;
				con[p][cc[p]++] = q;
			}
			deg[p]++;
			deg[q]++;
		}
		if (s)
		{
			f = 0;
			r = 0;
			for(i=0; i<n; i++)
			{
				if(deg[i])
				{
					if (r && used[i] != cnt)
					{
						break;
					}
					if (used[i] == cnt)
					{
						continue;
					}
					used[i] = cnt;
					dfs(i);
					if (f)
					{
						break;
					}
					r = 1;
				}
			}
		}
		if(i == n && s)
		{
			printf("Possible\n");
		}
		else
		{
			printf("Not Possible\n");
		}
	}
	return 0;
}
