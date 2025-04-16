#include <iostream>
#include <map>
using namespace std;

char buf[64];

int main()
{
	int n, i;
	scanf("%d", &n);
	int best = 0;
	string ans;
	map<string, int> mp;
	for (i=0; i<n; i++)
	{
		scanf("%s", buf);
		int c = ++mp[buf];
		if (c > best)
		{
			best = c;
			ans = buf;
		}
	}
	puts(ans.c_str());
	return 0;
}
