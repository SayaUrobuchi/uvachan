#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int N = 200005;

int ary[N], cnt[N];

int main()
{
	int n, i;
	scanf("%d", &n);
	for (i=0; i<n; i++)
	{
		scanf("%d", &ary[i]);
		++cnt[ary[i]];
	}
	priority_queue<int, vector<int>, greater<int> > pq;
	for (i=1; i<=n; i++)
	{
		if (cnt[i] == 0)
		{
			pq.emplace(i);
		}
	}
	bool gg = false;
	vector<int> ans;
	for (i=0; i<n&&!gg; i++)
	{
		if (pq.empty())
		{
			gg = true;
		}
		else
		{
			ans.emplace_back(pq.top());
			pq.pop();
			if (!(--cnt[ary[i]]))
			{
				pq.emplace(ary[i]);
			}
		}
	}
	if (gg)
	{
		puts("Error");
	}
	else
	{
		for (i=0; i<ans.size(); i++)
		{
			printf("%d\n", ans[i]);
		}
	}
	return 0;
}
