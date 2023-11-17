#include <iostream>
#include <map>
using namespace std;

const int N = 205;

int tbl[128];
char s[N];

int main()
{
	int n, i, j, best, mx, mn;
	map<int, int> mp;
	scanf("%d%s", &n, s);
	for (i=0, best=1; i+best<n; i++)
	{
		mp.clear();
		for (j='a'; j<='z'; j++)
		{
			tbl[j] = 0;
		}
		for (j=i; j<n; j++)
		{
			if (tbl[s[j]])
			{
				auto it = mp.find(tbl[s[j]]);
				if (--(it->second) == 0)
				{
					mp.erase(it);
				}
			}
			++mp[++tbl[s[j]]];
			mn = (mp.begin())->first;
			auto it = mp.end();
			--it;
			mx = it->first;
			if (mn == mx)
			{
				best = max(best, j-i+1);
			}
		}
	}
	printf("%d\n", best);
	return 0;
}