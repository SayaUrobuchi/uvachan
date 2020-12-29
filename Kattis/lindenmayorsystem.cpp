#include <iostream>
using namespace std;

string str[128], ary[128];

int main()
{
	int n, m, i, j;
	char c;
	string s;
	while (cin >> n >> m)
	{
		for (i='A'; i<='Z'; i++)
		{
			str[i].clear();
			str[i] += i;
		}
		for (i=0; i<n; i++)
		{
			cin >> s;
			c = s[0];
			cin >> s >> str[c];
		}
		cin >> ary[0];
		for (i=1; i<=m; i++)
		{
			ary[i].clear();
			for (j=0; j<ary[i-1].size(); j++)
			{
				ary[i] += str[ary[i-1][j]];
			}
		}
		cout << ary[m] << "\n";
	}
	return 0;
}
