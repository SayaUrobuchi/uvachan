#include <iostream>
using namespace std;

int tbl[128];
string key[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
string str[1048576];

int main()
{
	int n, i, j, ans;
	string s;
	for (i=2; i<=9; i++)
	{
		for (j=0; j<key[i].size(); j++)
		{
			tbl[key[i][j]] = '0'+i;
		}
	}
	while (cin >> n)
	{
		for (i=0; i<n; i++)
		{
			cin >> str[i];
		}
		cin >> s;
		for (i=0, ans=0; i<n; i++)
		{
			if (str[i].size() == s.size())
			{
				for (j=0; j<s.size()&&tbl[str[i][j]]==s[j]; j++);
				if (j >= s.size())
				{
					++ans;
				}
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
