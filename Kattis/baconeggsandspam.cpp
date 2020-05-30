#include <iostream>
#include <sstream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

map<string, int> tbl;
vector<string> v[128];

int main()
{
	int n, i, j, k;
	string s, t, nam;
	while (cin >> n)
	{
		if (n == 0)
		{
			break;
		}
		tbl.clear();
		getline(cin, s);
		for (i=0, j=1; i<n; i++)
		{
			getline(cin, s);
			stringstream ss(s);
			ss >> nam;
			while (ss >> t)
			{
				k = tbl[t];
				if (!k)
				{
					v[j].clear();
					tbl[t] = k = j++;
				}
				v[k].emplace_back(nam);
			}
		}
		for (map<string, int>::iterator it=tbl.begin(); it!=tbl.end(); ++it)
		{
			cout << it->first;
			k = it->second;
			sort(v[k].begin(), v[k].end());
			for (i=0; i<v[k].size(); i++)
			{
				cout << " " << v[k][i];
			}
			cout << "\n";
		}
		cout << "\n";
	}
	return 0;
}
