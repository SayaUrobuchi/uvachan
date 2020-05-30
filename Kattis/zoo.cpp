#include <iostream>
#include <sstream>
#include <map>
#include <algorithm>
using namespace std;

map<string, int> tbl;

void lower(string &s)
{
	int i;
	for (i=0; i<s.size(); i++)
	{
		if (s[i] >= 'A' && s[i] <= 'Z')
		{
			s[i] |= 32;
		}
	}
}

int main()
{
	int cas, n, i;
	string s, t;
	cas = 0;
	while (cin >> n)
	{
		if (n == 0)
		{
			break;
		}
		tbl.clear();
		getline(cin, s);
		for (i=0; i<n; i++)
		{
			getline(cin, s);
			stringstream ss(s);
			while (ss >> t);
			lower(t);
			++tbl[t];
		}
		cout << "List " << ++cas << ":\n";
		for (map<string, int>::iterator it=tbl.begin(); it!=tbl.end(); ++it)
		{
			cout << it->first << " | " << it->second << "\n";
		}
	}
	return 0;
}
