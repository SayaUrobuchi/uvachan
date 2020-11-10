#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
	int t;
	bool res;
	string cmd, nam, nam2;
	unordered_map<string, int> tbl;
	while (cin >> cmd)
	{
		if (cmd == "define")
		{
			cin >> t >> nam;
			tbl[nam] = t;
		}
		else
		{
			cin >> nam >> cmd >> nam2;
			if (tbl.find(nam) == tbl.end() || tbl.find(nam2) == tbl.end())
			{
				cout << "undefined\n";
			}
			else
			{
				if (cmd == "<")
				{
					res = (tbl[nam] < tbl[nam2]);
				}
				else if (cmd == "=")
				{
					res = (tbl[nam] == tbl[nam2]);
				}
				else
				{
					res = (tbl[nam] > tbl[nam2]);
				}
				cout << (res?"true":"false") << "\n";
			}
		}
	}
	return 0;
}
