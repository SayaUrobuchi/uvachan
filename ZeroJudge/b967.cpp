#include <stdio.h>
#include <vector>

int mm, ans;
int used[100000], cnt;
std::vector<int> cc[100000];

void dfs(int par, int now, int depth)
{
	int i;
	if (depth > ans)
	{
		ans = depth;
		mm = now;
	}
	for (i=0; i<cc[now].size(); i++)
	{
		if (cc[now][i] != par)
		{
			dfs(now, cc[now][i], depth+1);
		}
	}
}

int main()
{
	int cnt, n, i, p, q;
	cnt = 0;
	while (scanf("%d", &n) == 1)
	{
		++cnt;
		for (i=1; i<n; i++)
		{
			scanf("%d%d", &p, &q);
			if (used[p] != cnt)
			{
				used[p] = cnt;
				cc[p].clear();
			}
			cc[p].push_back(q);
			if (used[q] != cnt)
			{
				used[q] = cnt;
				cc[q].clear();
			}
			cc[q].push_back(p);
		}
		mm = 0;
		ans = 0;
		dfs(-1, 0, 0);
		dfs(-1, mm, 0);
		printf("%d\n", ans);
	}
	return 0;
}
