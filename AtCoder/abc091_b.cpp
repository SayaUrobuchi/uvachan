#include <iostream>
#include <map>
using namespace std;

void build(int c, map<string, int> &mp)
{
	int n, i;
	char buf[16];
	scanf("%d", &n);
	for (i=0; i<n; i++)
	{
		scanf("%s", buf);
		mp[buf] += c;
	}
}

int main()
{
	int ans;
	map<string, int> mp;
	build(1, mp);
	build(-1, mp);
	ans = 0;
	for (decltype(mp)::iterator it=mp.begin(); it!=mp.end(); ++it)
	{
		ans = max(ans, it->second);
	}
	printf("%d\n", ans);
	return 0;
}