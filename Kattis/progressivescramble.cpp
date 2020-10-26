#include <iostream>
using namespace std;

int tbl[128];

int main()
{
	int count, i, t, u;
	char cmd;
	string s, key;
	key = " ";
	for (i='a'; i<='z'; i++)
	{
		key += (char)i;
	}
	for (i=0; i<key.size(); i++)
	{
		tbl[key[i]] = i;
	}
	cin >> count;
	while (count--)
	{
		cin >> cmd;
		getline(cin, s);
		if (cmd == 'e')
		{
			for (i=1, t=0; i<s.size(); i++)
			{
				t += tbl[s[i]];
				cout << key[t%27];
			}
			cout << "\n";
		}
		else
		{
			for (i=1, t=0; i<s.size(); i++)
			{
				u = (tbl[s[i]]+27-t%27)%27;
				cout << key[u];
				t += u;
			}
			cout << "\n";
		}
	}
	return 0;
}
