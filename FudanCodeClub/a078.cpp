#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
using pp = pair<int, int>;

int main()
{
	int count;
	scanf("%d", &count);
	while (count--)
	{
		int n, i;
		scanf("%d", &n);
		vector<pp> ary(n);
		for (i=0; i<n; i++)
		{
			scanf("%d%d", &ary[i].second, &ary[i].first);
		}
		sort(ary.begin(), ary.end());
		priority_queue<int> pq;
		long long sum = 0;
		for (i=0; i<n; i++)
		{
			pq.emplace(ary[i].second);
			sum += ary[i].second;
			if (sum > ary[i].first)
			{
				sum -= pq.top();
				pq.pop();
			}
		}
		printf("%d\n", (int)pq.size());
	}
	return 0;
}