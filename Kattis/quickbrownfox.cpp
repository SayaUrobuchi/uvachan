#include <iostream>
using namespace std;

int ucnt;
int idd[128], used[128];

int main()
{
	int count, i, c;
	string s;
	for (i=0; i<26; i++)
	{
		idd[i+'a'] = idd[i+'A'] = i+1;
	}
	cin >> count;
	getline(cin, s);
	while (count--)
	{
		getline(cin, s);
		ucnt++;
		for (i=0, c=0; i<s.size(); i++)
		{
			if (idd[s[i]])
			{
				if (used[idd[s[i]]] != ucnt)
				{
					used[idd[s[i]]] = ucnt;
					c++;
				}
			}
		}
		if (c == 26)
		{
			cout << "pangram\n";
			continue;
		}
		cout << "missing ";
		for (i=1; i<=26; i++)
		{
			if (used[i] != ucnt)
			{
				cout << (char)(i+'a'-1);
			}
		}
		cout << "\n";
	}
	return 0;
}