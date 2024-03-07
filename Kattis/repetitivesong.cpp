#include <iostream>
#include <map>
using namespace std;

char buf[32];

int main()
{
	int n, i;
	scanf("%d", &n);
	int best = n;
	map<string, int> mp;
	for (i=0; i<n; i++)
	{
		scanf("%s", buf);
		decltype(mp)::iterator it = mp.find(buf);
		if (it != mp.end())
		{
			best = min(best, i-it->second);
			it->second = i;
		}
		else
		{
			mp[buf] = i;
		}
	}
	printf("%d\n", n-best);
	return 0;
}