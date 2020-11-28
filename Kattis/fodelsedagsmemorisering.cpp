#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

using pp = pair<int, string>;
using mm = unordered_map<int, pp>;

int main()
{
	int n, i, k, t, mon, day;
	string nam, s;
	mm tbl;
	vector<string> v;
	while (cin >> n)
	{
		tbl.clear();
		for (i=0; i<n; i++)
		{
			cin >> nam >> t >> s;
			++t;
			sscanf(s.c_str(), "%d/%d", &mon, &day);
			k = (mon<<5) + day;
			pp p = {t, nam};
			tbl[k] = max(tbl[k], p);
		}
		v.clear();
		for (mm::iterator it=tbl.begin(); it!=tbl.end(); it++)
		{
			v.emplace_back((it->second).second);
		}
		sort(v.begin(), v.end());
		cout << v.size() << "\n";
		for (i=0; i<v.size(); i++)
		{
			cout << v[i] << "\n";
		}
	}
	return 0;
}
