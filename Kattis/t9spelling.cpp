#include <iostream>
using namespace std;

const char *key[] = {" ", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
char tbl[128][8];

int main()
{
	int count, cas, i, j, k, t, last;
	string s;
	cas = 0;
	for (i=0; i<10; i++)
	{
		for (j=0; t=key[i][j]; j++)
		{
			for (k=0; k<=j; k++)
			{
				tbl[t][k] = i+'0';
			}
			tbl[t][k] = 0;
		}
	}
	cin >> count;
	getline(cin, s);
	while (count--)
	{
		getline(cin, s);
		cout << "Case #" << ++cas << ": ";
		for (i=0, last=-1; i<s.size(); i++)
		{
			if (*tbl[s[i]] == last)
			{
				cout << ' ';
			}
			cout << tbl[s[i]];
			last = *tbl[s[i]];
		}
		cout << "\n";
	}
	return 0;
}
