#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
	int n, i, j, t;
	string s;
	unordered_map<string, bool> tbl;
	while (cin >> n)
	{
		getline(cin, s);
		tbl.clear();
		for (i=0, t=0; i<n; i++)
		{
			getline(cin, s);
			for (j=0; j<s.size(); j++)
			{
				if (s[j] == ' ')
				{
					s[j] = '-';
				}
				else if (s[j] >= 'A' && s[j] <= 'Z')
				{
					s[j] |= 32;
				}
			}
			if (tbl.find(s) == tbl.end())
			{
				++t;
				tbl[s] = true;
			}
		}
		cout << t << "\n";
	}
	return 0;
}
