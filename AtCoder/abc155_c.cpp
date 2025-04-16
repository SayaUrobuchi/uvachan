#include <iostream>
#include <map>
using namespace std;

char buf[16];

int main()
{
	int n, i;
	scanf("%d", &n);
	int most = 0;
	map<string, int> mp;
	for (i=0; i<n; i++)
	{
		scanf("%s", buf);
		most = max(most, ++mp[buf]);
	}
	for (auto &it : mp)
	{
		if (it.second == most)
		{
			puts((it.first).c_str());
		}
	}
	return 0;
}
