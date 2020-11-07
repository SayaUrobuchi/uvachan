#include <iostream>
#include <sstream>
#include <unordered_map>
using namespace std;

string nam[128];
unordered_map<string, int> tbl;
char buf[1024];

int main()
{
	int count, n, i;
	bool first;
	string s;
	cin >> count;
	getline(cin, s);
	while (count--)
	{
		getline(cin, s);
		stringstream ss(s);
		for (i=0; ss>>nam[i]; i++);
		n = i;
		tbl.clear();
		while (getline(cin, s))
		{
			if (sscanf(s.c_str(), "%*s goes %s", buf) != 1)
			{
				break;
			}
			tbl[buf] = 1;
		}
		for (i=0, first=true; i<n; i++)
		{
			if (tbl.find(nam[i]) == tbl.end())
			{
				if (!first)
				{
					cout << " ";
				}
				first = false;
				cout << nam[i];
			}
		}
		cout << "\n";
	}
	return 0;
}
