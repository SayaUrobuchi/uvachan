#include <iostream>
#include <map>
using namespace std;

string s[1048576];
map<string, bool> tbl;

int main()
{
	int i, j;
	i = 0;
	while (cin >> s[i])
	{
		for (j=0; j<i; j++)
		{
			tbl[s[i]+s[j]] = true;
			tbl[s[j]+s[i]] = true;
		}
		i++;
	}
	for (map<string, bool>::iterator it=tbl.begin(); it!=tbl.end(); ++it)
	{
		cout << it->first << "\n";
	}
	return 0;
}
