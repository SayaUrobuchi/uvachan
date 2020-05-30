#include <iostream>
#include <unordered_map>
using namespace std;

unordered_map<string, bool> tbl;

int main()
{
	int n, m, i, cd, ans;
	string s;
	while (cin >> n >> m)
	{
		tbl.clear();
		for (i=0, cd=n; i<m; i++)
		{
			cin >> s;
			if (!tbl[s])
			{
				tbl[s] = true;
				--cd;
				if (cd == 0)
				{
					ans = i+1;
				}
			}
		}
		if (cd)
		{
			cout << "paradox avoided\n";
		}
		else
		{
			cout << ans << "\n";
		}
	}
	return 0;
}
