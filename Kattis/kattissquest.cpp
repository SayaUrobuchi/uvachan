#include <iostream>
#include <set>
using namespace std;
using pp = pair<int, int>;
using ppp = pair<pp, int>;

int main()
{
	int n, i, a, b;
	char cmd[128];
	set<ppp> se;
	scanf("%d", &n);
	for (i=0; i<n; i++)
	{
		scanf("%s", cmd);
		if (*cmd == 'a')
		{
			scanf("%d%d", &a, &b);
			se.insert(make_pair(make_pair(a, b), i));
		}
		else
		{
			scanf("%d", &a);
			long long res = 0;
			while (a > 0)
			{
				decltype(se)::iterator it = se.lower_bound(make_pair(make_pair(a+1, 0), 0));
				if (it == se.begin())
				{
					break;
				}
				--it;
				a -= (it->first).first;
				res += (it->first).second;
				se.erase(it);
			}
			printf("%lld\n", res);
		}
	}
	return 0;
}
