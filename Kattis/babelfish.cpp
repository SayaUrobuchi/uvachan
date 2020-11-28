#include <iostream>
#include <sstream>
#include <unordered_map>
using namespace std;

using mm = unordered_map<string, string>;

int main()
{
	string s, a, b;
	mm tbl;
	while (getline(cin, s))
	{
		if (s.empty())
		{
			break;
		}
		stringstream ss(s);
		ss >> a >> b;
		tbl[b] = a;
	}
	while (cin >> s)
	{
		mm::iterator it = tbl.find(s);
		if (it == tbl.end())
		{
			cout << "eh\n";
		}
		else
		{
			cout << it->second << "\n";
		}
	}
	return 0;
}
