#include <iostream>
using namespace std;

char u;
int tbl[128];

void rec(char c)
{
	int i;
	if (c > 'Z')
	{
		if (u != -1)
		{
			cout << u;
		}
		return;
	}
	for (i=1; (i<<1)<=tbl[c]; i++)
	{
		cout << c;
	}
	rec(c+1);
	for (i=1; (i<<1)<=tbl[c]; i++)
	{
		cout << c;
	}
}

int main()
{
	int i, t;
	string s;
	while (cin >> s)
	{
		for (i='A'; i<='Z'; i++)
		{
			tbl[i] = 0;
		}
		for (i=0; i<s.size(); i++)
		{
			++tbl[s[i]];
		}
		for (i='A', t=0, u=-1; i<='Z'; i++)
		{
			if (tbl[i] & 1)
			{
				++t;
				u = i;
			}
		}
		if (t > 1)
		{
			cout << "NO SOLUTION\n";
		}
		else
		{
			rec('A');
			cout << "\n";
		}
	}
	return 0;
}

