#include <iostream>
using namespace std;

string key = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";
int tbl[128];

int main()
{
	int i;
	string s;
	for (i=1; i<key.size(); i++)
	{
		tbl[ key[i] ] = key[i-1];
	}
	tbl[' '] = ' ';
	while (getline(cin, s))
	{
		for (i=0; i<s.size(); i++)
		{
			s[i] = tbl[ s[i] ];
		}
		cout << s << '\n';
	}
	return 0;
}
