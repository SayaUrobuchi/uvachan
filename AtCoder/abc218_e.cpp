#include <iostream>
#include <algorithm>
using namespace std;
using pp = pair<int, int>;
using ppp = pair<int, pp>;

const int N = 262144;

int par[N], rnk[N];
ppp ary[N];

int getpar(int cur)
{
	if (par[cur] < 0)
	{
		return cur;
	}
	return par[cur] = getpar(par[cur]);
}

int main()
{
	int n, m, i, t, a, b;
	long long ans;
	while (scanf("%d%d", &n, &m) == 2)
	{
		for (i=1; i<=n; i++)
		{
			par[i] = -1;
			rnk[i] = 0;
		}
		for (i=0; i<m; i++)
		{
			scanf("%d%d%d", &ary[i].second.first, &ary[i].second.second, &ary[i].first);
		}
		sort(ary, ary+m);
		for (i=0, t=1, ans=0; i<m; i++)
		{
			if (t == n)
			{
				if (ary[i].first > 0)
				{
					ans += ary[i].first;
				}
			}
			else
			{
				a = getpar(ary[i].second.first);
				b = getpar(ary[i].second.second);
				if (a != b)
				{
					if (rnk[a] > rnk[b])
					{
						swap(a, b);
					}
					par[a] = b;
					if (rnk[a] == rnk[b])
					{
						++rnk[b];
					}
				}
				else if (ary[i].first > 0)
				{
					ans += ary[i].first;
				}
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}

