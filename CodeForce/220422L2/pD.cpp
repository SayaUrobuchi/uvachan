#include <iostream>
#include <set>
using namespace std;

long long rat[100005];

int main()
{
	int n, m, i, j, o, t, u;
	set<pair<long long, int> > se;
	while (scanf("%d%d", &n, &m) == 2)
	{
		se.clear();
		for (i=1; i<=n; i++)
		{
			scanf("%lld", &rat[i]);
			if (i >= 2 && rat[i] >= rat[1])
			{
				se.insert({rat[i], i});
			}
		}
		for (i=0; i<m; i++)
		{
			scanf("%d", &o);
			for (j=0; j<o; j++)
			{
				scanf("%d%d", &u, &t);
				if (se.count({rat[u], u}))
				{
					se.erase({rat[u], u});
					rat[u] += t;
					se.insert({rat[u], u});
				}
				else if (u == 1)
				{
					rat[u] += t;
				}
			}
			auto it = se.lower_bound({rat[1], 1});
			if (it != se.begin())
			{
				--it;
				while (true)
				{
					auto ip = it;
					if (it == se.begin())
					{
						se.erase(ip);
						break;
					}
					--it;
					se.erase(ip);
				}
			}
		}
		printf("%d\n", se.size());
	}
	return 0;
}

