#include <iostream>
using namespace std;

const char *key[] = {"@", "8", "(", "|)", "3", "#", "6", "[-]", "|", "_|", "|<", "1", "[]\\/[]", 
"[]\\[]", "0", "|D", "(,)", "|Z", "$", "']['", "|_|", "\\/", "\\/\\/", "}{", "`/", "2"};
string tbl[128];

int main()
{
	int i;
	string s;
	for (i=32; i<127; i++)
	{
		tbl[i] += (char)i;
	}
	for (i=0; i<26; i++)
	{
		tbl['A'+i] = tbl['a'+i] = key[i];
	}
	while (getline(cin, s))
	{
		for (i=0; i<s.size(); i++)
		{
			cout << tbl[s[i]];
		}
		cout << "\n";
	}
	return 0;
}
