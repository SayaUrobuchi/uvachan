#include <iostream>
#include <map>
#include <set>
using namespace std;

const int N = 100005;
const int SN = 32;

char str[N][SN];
char buf[SN], buf2[SN];
bool hunter[N];

int main()
{
	int n, m, i;
	scanf("%d%d", &n, &m);
	map<string, int> mp;
	for (i=0; i<n; i++)
	{
		scanf("%s", str[i]);
		mp[str[i]] = i;
	}
	hunter[0] = true;
	set<string> se;
	for (i=0; i<m; i++)
	{
		scanf("%s tar %s", buf, buf2);
		int a = mp[buf];
		int b = mp[buf2];
		if (!hunter[a])
		{
			se.insert(buf);
		}
		hunter[a] = false;
		hunter[b] = true;
	}
	printf("%llu\n", se.size());
	bool ff = false;
	for (decltype(se)::iterator it=se.begin(); it!=se.end(); ++it)
	{
		if (ff)
		{
			putchar(' ');
		}
		ff = true;
		printf("%s", it->c_str());
	}
	puts("");
	return 0;
}
