#include <iostream>
#include <map>
using namespace std;

int main()
{
	string s;
	map<string, int> tbl;
	int n = 0;
	while (getline(cin, s))
	{
		++tbl[s];
		++n;
	}
	for (map<string, int>::iterator it=tbl.begin(); it!=tbl.end(); ++it)
	{
		printf("%s %.10lf\n", (it->first).c_str(), it->second*100.0/n);
	}
	return 0;
}
