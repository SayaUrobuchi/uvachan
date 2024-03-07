#include <iostream>
#include <map>
using namespace std;

const int N = 16;

int cnt[N];
char buf[8];

int main()
{
	int n, m, i, j;
	map<string, int> mpp, mpr;
	scanf("%d", &n);
	for (i=0; i<n; i++)
	{
		int t;
		scanf("%s%d", buf, &t);
		mpp[buf] = i;
		for (j=0; j<t; j++)
		{
			scanf("%s", buf);
			mpr[buf] = i;
		}
	}
	scanf("%d", &m);
	for (i=0; i<m; i++)
	{
		int t;
		scanf("%d%s", &t, buf);
		cnt[mpr[buf]] += t;
	}
	for (decltype(mpp)::iterator it=mpp.begin(); it!=mpp.end(); ++it)
	{
		printf("%s %d\n", (it->first).c_str(), cnt[it->second]);
	}
	return 0;
}
