#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
using pp = pair<int, int>;

pp ary[262144];

int main()
{
	int count, n, i, j;
	bool gg;
	scanf("%d", &count);
	while (count--)
	{
		scanf("%d", &n);
		for (i=0; i<n; i++)
		{
			scanf("%d%d", &ary[i].first, &ary[i].second);
		}
		sort(ary, ary+n);
		priority_queue<int, vector<int>, greater<int> > pq;
		for (i=1, j=0, gg=false; ; )
		{
			for (; j<n&&ary[j].first==i; j++)
			{
				pq.emplace(ary[j].second);
			}
			if (pq.empty())
			{
				if (j >= n)
				{
					break;
				}
				i = ary[j].first;
				continue;
			}
			if (pq.top() < i)
			{
				gg = true;
				break;
			}
			pq.pop();
			++i;
		}
		puts(gg?"No":"Yes");
	}
	return 0;
}

