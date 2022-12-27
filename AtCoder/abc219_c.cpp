#include <iostream>
#include <algorithm>
using namespace std;

string str[65536];
char key[128], buf[128];
int tbl[128];

bool comp(const string &a, const string &b)
{
	int i;
	for (i=0; i<a.size()&&i<b.size(); i++)
	{
		if (a[i] != b[i])
		{
			return tbl[a[i]] < tbl[b[i]];
		}
	}
	return a.size() < b.size();
}

int main()
{
	int n, i;
	while (scanf("%s%d", key, &n) == 2)
	{
		for (i=0; key[i]; i++)
		{
			tbl[key[i]] = i;
		}
		for (i=0; i<n; i++)
		{
			scanf("%s", buf);
			str[i] = buf;
		}
		sort(str, str+n, comp);
		for (i=0; i<n; i++)
		{
			puts(str[i].c_str());
		}
	}
	return 0;
}

