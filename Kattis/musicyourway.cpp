#include <iostream>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

struct dd
{
	string str[32];
};

int idx;

bool comp(dd p, dd q)
{
	return p.str[idx] < q.str[idx];
}

int main()
{
	int n, m, o, i, j, k;
	string s, title;
	unordered_map<string, int> tbl;
	vector<dd> v;
	while (getline(cin, s))
	{
		title = s;
		stringstream ss(s);
		tbl.clear();
		i = 0;
		while (ss >> s)
		{
			tbl[s] = i;
			++i;
		}
		o = i;
		cin >> n;
		getline(cin, s);
		v.resize(n);
		for (i=0; i<n; i++)
		{
			getline(cin, s);
			j = 0;
			stringstream ss(s);
			while (ss >> s)
			{
				v[i].str[j] = s;
				++j;
			}
		}
		cin >> m;
		for (i=0; i<m; i++)
		{
			cin >> s;
			idx = tbl[s];
			stable_sort(v.begin(), v.end(), comp);
			if (i)
			{
				cout << "\n";
			}
			cout << title << "\n";
			for (j=0; j<n; j++)
			{
				cout << v[j].str[0];
				for (k=1; k<o; k++)
				{
					cout << " " << v[j].str[k];
				}
				cout << "\n";
			}
		}
		getline(cin, s);
	}
	return 0;
}
