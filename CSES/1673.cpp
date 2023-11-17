#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

const int N = 2505;

bool used[N], inf[N];
long long dis[N];
vector<pair<int, int> > eu[N], ed[N];

int main()
{
	int n, m, i, j, k, a, b, c;
	scanf("%d%d", &n, &m);
	for (i=0; i<m; i++)
	{
		scanf("%d%d%d", &a, &b, &c);
		if (a < b)
		{
			eu[a].emplace_back(b, c);
		}
		else
		{
			ed[a].emplace_back(b, c);
		}
	}
	used[1] = true;
	bool is_upd = true;
	for (i=0; i<n+n&&is_upd; i++)
	{
		is_upd = false;
		for (j=1; j<=n; j++)
		{
			if (used[j])
			{
				for (k=0; k<eu[j].size(); k++)
				{
					int t, d;
					tie(t, d) = eu[j][k];
					if (!used[t] || dis[t] < dis[j] + d || inf[j])
					{
						dis[t] = dis[j] + d;
						used[t] = true;
						is_upd = true;
						if ((i<<1) > n || inf[j])
						{
							inf[t] = true;
						}
					}
				}
			}
		}
		for (j=n; j>=1; j--)
		{
			if (used[j])
			{
				for (k=0; k<ed[j].size(); k++)
				{
					int t, d;
					tie(t, d) = ed[j][k];
					if (!used[t] || dis[t] < dis[j] + d || inf[j])
					{
						dis[t] = dis[j] + d;
						used[t] = true;
						is_upd = true;
						if ((i<<1) > n || inf[j])
						{
							inf[t] = true;
						}
					}
				}
			}
		}
	}
	if (inf[n])
	{
		puts("-1");
	}
	else
	{
		printf("%lld\n", dis[n]);
	}
	return 0;
}
