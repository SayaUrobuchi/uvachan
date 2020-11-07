#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

struct dat
{
	string nam;
	int cnt;
};

vector<dat> v;
unordered_map<string, int> mtbl;

bool comp(dat &p, dat &q)
{
	if (p.cnt != q.cnt)
	{
		return p.cnt > q.cnt;
	}
	return p.nam < q.nam;
}

int main()
{
	int count, n, i, t;
	string s;
	cin >> count;
	while (count--)
	{
		mtbl.clear();
		v.clear();
		cin >> n;
		for (i=0; i<n; i++)
		{
			cin >> s >> t;
			if (mtbl[s] == 0)
			{
				v.push_back({s, 0});
				mtbl[s] = v.size();
			}
			v[mtbl[s]-1].cnt += t;
		}
		sort(v.begin(), v.end(), comp);
		cout << v.size() << "\n";
		for (i=0; i<v.size(); i++)
		{
			cout << v[i].nam << " " << v[i].cnt << "\n";
		}
	}
	return 0;
}
