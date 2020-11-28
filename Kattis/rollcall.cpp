#include <iostream>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int main()
{
	int i;
	string s, first, second;
	unordered_map<string, int> tbl;
	vector<pair<string, string> > v;
	while (getline(cin, s))
	{
		stringstream ss(s);
		ss >> first >> second;
		++tbl[first];
		v.push_back({second, first});
	}
	sort(v.begin(), v.end());
	for (i=0; i<v.size(); i++)
	{
		if (tbl[v[i].second] > 1)
		{
			cout << v[i].second << " " << v[i].first << "\n";
		}
		else
		{
			cout << v[i].second << "\n";
		}
	}
	return 0;
}
