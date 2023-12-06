#include <iostream>
#include <algorithm>
using namespace std;
using pp = pair<string, int>;

const int N = 1024;
const int M = 1048576;
const int SLEN = 16;

int cnt[N];
pp ary[M];
char buf[SLEN];

int main()
{
	int n, m, i, j, needed;
	scanf("%d%d", &m, &n);
	for (i=0; i<n; i++)
	{
		scanf("%d", &cnt[i]);
	}
	for (i=0; i<m; i++)
	{
		scanf("%s%d", buf, &ary[i].second);
		ary[i].first = buf;
	}
	sort(ary, ary+m);
	for (i=0; i<n; i++)
	{
		for (j=0, needed=0; j<cnt[i]; j++)
		{
			int cur;
			scanf("%s%d", buf, &cur);
			string s = buf;
			pp *k = lower_bound(ary, ary+m, make_pair(s, -1));
			needed += k->second - cur;
		}
		printf("%d\n", needed);
	}
	return 0;
}
