#include <iostream>
#include <set>
#include <algorithm>
using namespace std;
using pp = pair<int, int>;
using ppp = pair<int, pp>;

int ary[1024];

int main()
{
	int n, m, i, j, t, a, b, c, d;
	bool found;
	while (scanf("%d%d", &n, &m) == 2)
	{
		for (i=0; i<n; i++)
		{
			scanf("%d", &ary[i]);
		}
		if (n < 4)
		{
			puts("IMPOSSIBLE");
			continue;
		}
		set<ppp> se;
		se.insert({ary[n-1]+ary[n-2], {n-1, n-2}});
		for (j=n-3, found=false; j>=1&&!found; j--)
		{
			for (i=0; i<j; i++)
			{
				t = m - (ary[i]+ary[j]);
				auto it = se.lower_bound({t, {i, j}});
				if (it != se.end() && it->first == t)
				{
					found = true;
					a = i;
					b = j;
					c = (it->second).first;
					d = (it->second).second;
				}
			}
			for (i=j+1; i<n; i++)
			{
				se.insert({ary[j]+ary[i], {j, i}});
			}
		}
		if (found)
		{
			printf("%d %d %d %d\n", a+1, b+1, c+1, d+1);
		}
		else
		{
			puts("IMPOSSIBLE");
		}
	}
	return 0;
}

