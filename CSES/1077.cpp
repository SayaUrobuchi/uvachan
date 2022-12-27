#include <iostream>
#include <set>
using namespace std;
using pp = pair<int, int>;

int ary[262144];

int main()
{
	int n, m, i, last;
	long long sua, sub;
	while (scanf("%d%d", &n, &m) == 2)
	{
		set<pp> sa, sb;
		sua = sub = 0;
		for (i=0, last=2e9; i<n; i++)
		{
			scanf("%d", &ary[i]);
			if (ary[i] < last)
			{
				sa.insert({ary[i], i});
				sua += ary[i];
			}
			else
			{
				sb.insert({ary[i], i});
				sub += ary[i];
			}
			while (sa.size() > sb.size()+1)
			{
				auto it = sa.end();
				--it;
				sub += it->first;
				sua -= it->first;
				sb.insert({it->first, it->second});
				sa.erase(it);
			}
			while (sb.size() > sa.size())
			{
				auto it = sb.begin();
				sua += it->first;
				sub -= it->first;
				sa.insert({it->first, it->second});
				sb.erase(it);
			}
			last = (sa.rbegin())->first;
			if (i >= m-1)
			{
				printf(i>=m?" %lld":"%lld", last*(long long)sa.size()-sua+sub-last*(long long)sb.size());
				pp tar = {ary[i-(m-1)], i-(m-1)};
				if (sa.count(tar))
				{
					sa.erase(tar);
					sua -= tar.first;
				}
				else
				{
					sb.erase(tar);
					sub -= tar.first;
				}
			}
		}
		puts("");
	}
	return 0;
}

