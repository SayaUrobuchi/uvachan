#include <iostream>
#include <set>
using namespace std;

const int N = 16;
const int SLEN = 32;

int cnt[N];
char nam[N][SLEN], buf[SLEN];
set<string> se[N];

int main()
{
	int n, i, j;
	scanf("%d", &n);
	for (i=1; i<=n; i++)
	{
		int t;
		scanf("%s%d", nam[i], &t);
		for (j=0; j<t; j++)
		{
			scanf("%s", buf);
			se[i].insert(buf);
		}
	}
	while (scanf("%s", buf) == 1)
	{
		string s = buf;
		for (i=1; i<=n; i++)
		{
			cnt[i] += se[i].count(s);
		}
	}
	int best = 0;
	for (i=1; i<=n; i++)
	{
		best = max(best, cnt[i]);
	}
	set<string> ans;
	for (i=1; i<=n; i++)
	{
		if (cnt[i] == best)
		{
			ans.insert(nam[i]);
		}
	}
	for (decltype(ans)::iterator it=ans.begin(); it!=ans.end(); ++it)
	{
		puts(it->c_str());
	}
	return 0;
}
