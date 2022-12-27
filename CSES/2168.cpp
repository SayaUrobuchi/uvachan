#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using pp = pair<pair<int, int>, int>;
const int N = 262144;

int atk[N], def[N];
pp ary[N];

bool comp(const pp &a, const pp &b)
{
	if (a.first.first == b.first.first)
	{
		return a.first.second > b.first.second;
	}
	return a.first.first < b.first.first;
}

int main()
{
	int n, i, t, best;
	vector<pp> stk;
	while (cin >> n)
	{
		for (i=0; i<n; i++)
		{
			cin >> ary[i].first.first >> ary[i].first.second;
			ary[i].second = i;
			atk[i] = def[i] = false;
		}
		sort(ary, ary+n, comp);
		stk.clear();
		for (i=0, best=-1; i<n; i++)
		{
			t = ary[i].first.second;
			if (t <= best)
			{
				def[ary[i].second] = true;
			}
			else
			{
				best = t;
			}
			while (stk.size()&&stk.back().first.second>=t)
			{
				atk[stk.back().second] = true;
				stk.pop_back();
			}
			stk.emplace_back(ary[i]);
		}
		cout << atk[0];
		for (i=1; i<n; i++)
		{
			cout << " " << atk[i];
		}
		cout << "\n";
		cout << def[0];
		for (i=1; i<n; i++)
		{
			cout << " " << def[i];
		}
		cout << "\n";
	}
	return 0;
}

