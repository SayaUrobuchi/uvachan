#include <iostream>
#include <unordered_map>
using namespace std;

using mm = unordered_map<string, int>;

int sc[32];
string nam[32];

int main()
{
	int n, m, i, best, winner, id;
	bool gg;
	string s;
	mm tbl;
	while (cin >> n)
	{
		getline(cin, s);
		for (i=0; i<n; i++)
		{
			getline(cin, s);
			tbl[s] = i;
			sc[i] = 0;
			getline(cin, nam[i]);
		}
		cin >> m;
		getline(cin, s);
		for (i=0, best=0, gg=true; i<m; i++)
		{
			getline(cin, s);
			mm::iterator it = tbl.find(s);
			if (it != tbl.end())
			{
				id = it->second;
				++sc[id];
				if (sc[id] > best)
				{
					best = sc[id];
					winner = id;
					gg = false;
				}
				else if (sc[id] == best)
				{
					gg = true;
				}
			}
		}
		if (gg)
		{
			cout << "tie\n";
		}
		else
		{
			cout << nam[winner] << "\n";
		}
	}
	return 0;
}
