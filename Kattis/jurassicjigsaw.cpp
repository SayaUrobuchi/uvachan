#include <iostream>
#include <vector>
using namespace std;

int par[1024];
char s[1024][1024];
vector<pair<int, int> > v[16], edg;

int getpar(int cur)
{
	if (cur == par[cur])
	{
		return cur;
	}
	return par[cur] = getpar(par[cur]);
}

int comp(const char *p, const char *q)
{
	int res;
	for (res=0; *p; p++, q++)
	{
		if (*p != *q)
		{
			++res;
		}
	}
	return res;
}

int main()
{
	int n, m, i, j, k, ans, t, p, q;
	while (scanf("%d%d", &n, &m) == 2)
	{
		for (i=0; i<=m; i++)
		{
			v[i].clear();
		}
		for (i=0; i<n; i++)
		{
			par[i] = i;
			scanf("%s", s[i]);
			for (j=0; j<i; j++)
			{
				t = comp(s[i], s[j]);
				v[t].push_back({i, j});
			}
		}
		edg.clear();
		for (i=0, j=1, ans=0; j<n; i++)
		{
			for (k=0; k<v[i].size()&&j<n; k++)
			{
				p = v[i][k].first;
				q = v[i][k].second;
				if (getpar(p) != getpar(q))
				{
					++j;
					par[getpar(p)] = getpar(q);
					edg.push_back(v[i][k]);
					ans += i;
				}
			}
		}
		printf("%d\n", ans);
		for (i=0; i<edg.size(); i++)
		{
			printf("%d %d\n", edg[i].first, edg[i].second);
		}
	}
	return 0;
}
