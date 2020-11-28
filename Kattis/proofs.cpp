#include <iostream>
#include <sstream>
#include <unordered_map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, i, ans;
	bool gg, st;
	unordered_map<string, bool> tbl;
	string s;
	while (cin >> n)
	{
		getline(cin, s);
		tbl.clear();
		for (i=0, gg=false; i<n; i++)
		{
			getline(cin, s);
			if (!gg)
			{
				stringstream ss(s);
				for (st=false; ss>>s; )
				{
					if (s == "->")
					{
						st = true;
					}
					else
					{
						if (!st && tbl.find(s) == tbl.end())
						{
							gg = true;
							ans = i+1;
							break;
						}
						else if (st)
						{
							tbl[s] = true;
						}
					}
				}
			}
		}
		if (gg)
		{
			cout << ans << "\n";
		}
		else
		{
			cout << "correct\n";
		}
	}
	return 0;
}
