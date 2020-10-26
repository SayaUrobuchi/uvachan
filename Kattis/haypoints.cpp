#include <iostream>
#include <sstream>
#include <unordered_map>
using namespace std;

int main()
{
	int n, m, i, t, ans;
	string s;
	unordered_map<string, int> tbl;
	while (cin >> n >> m)
	{
		tbl.clear();
		for (i=0; i<n; i++)
		{
			cin >> s >> t;
			tbl[s] = t;
		}
		getline(cin, s);
		for (i=0; i<m; i++)
		{
			ans = 0;
			while (getline(cin, s))
			{
				if (s == ".")
				{
					break;
				}
				stringstream ss(s);
				while (ss >> s)
				{
					unordered_map<string, int>::iterator it = tbl.find(s);
					if (it != tbl.end())
					{
						ans += it->second;
					}
				}
			}
			cout << ans << "\n";
		}
	}
	return 0;
}
