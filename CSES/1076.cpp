#include <iostream>
#include <set>
using namespace std;
using pp = pair<int, int>;

int ary[262144];

int main()
{
	int n, m, i, last;
	while (scanf("%d%d", &n, &m) == 2)
	{
		set<pp> sa, sb;
		for (i=0, last=2e9; i<n; i++)
		{
			scanf("%d", &ary[i]);
			if (ary[i] < last)
			{
				sa.insert({ary[i], i});
			}
			else
			{
				sb.insert({ary[i], i});
			}
			while (sa.size() > sb.size()+1)
			{
				auto it = sa.end();
				--it;
				sb.insert({it->first, it->second});
				sa.erase(it);
			}
			while (sb.size() > sa.size())
			{
				auto it = sb.begin();
				sa.insert({it->first, it->second});
				sb.erase(it);
			}
			last = (sa.rbegin())->first;
			if (i >= m-1)
			{
				printf(i>=m?" %d":"%d", last);
				pp tar = {ary[i-(m-1)], i-(m-1)};
				if (sa.count(tar))
				{
					sa.erase(tar);
				}
				else
				{
					sb.erase(tar);
				}
			}
		}
		puts("");
	}
	return 0;
}

