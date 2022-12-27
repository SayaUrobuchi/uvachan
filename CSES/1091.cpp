#include <iostream>
#include <map>
using namespace std;

int main()
{
	int n, m, i, t;
	map<int, int> mp;
	while (cin >> n >> m)
	{
		mp.clear();
		for (i=0; i<n; i++)
		{
			cin >> t;
			++mp[t];
		}
		for (i=0; i<m; i++)
		{
			cin >> t;
			auto it = mp.upper_bound(t);
			if (it == mp.begin())
			{
				cout << "-1\n";
				continue;
			}
			--it;
			cout << it->first << "\n";
			if (!(--it->second))
			{
				mp.erase(it);
			}
		}
	}
	return 0;
}

