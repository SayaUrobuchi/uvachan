#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int cas, count;
	scanf("%d", &count);
	for (cas=1; cas<=count; ++cas)
	{
		int n, i, j;
		scanf("%d", &n);
		vector<int> ary(n);
		vector<int> lis(1, -1);
		vector<int> len(n);
		for (i=0; i<n; i++)
		{
			scanf("%d", &ary[i]);
			int idx = lower_bound(lis.begin(), lis.end(), ary[i]) - lis.begin();
			if (idx >= lis.size())
			{
				lis.emplace_back(ary[i]);
			}
			else
			{
				lis[idx] = ary[i];
			}
			len[i] = idx;
		}
		vector<int> accept(n, -1);
		int cur_len = lis.size() - 1;
		accept[cur_len] = 2e9;
		vector<int> ans;
		for (i=n-1; i>=0; i--)
		{
			if (ary[i] < accept[len[i]])
			{
				ans.emplace_back(i+1);
				accept[len[i] - 1] = ary[i];
			}
		}
		reverse(ans.begin(), ans.end());
		printf("%llu\n", ans.size());
		for (i=0; i<ans.size(); i++)
		{
			printf("%d%c", ans[i], " \n"[i+1==ans.size()]);
		}
	}
	return 0;
}
