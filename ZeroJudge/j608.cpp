#include <iostream>
#include <algorithm>
using namespace std;

int ed[105];
pair<int, int> ary[100005];

int main()
{
	int n, k, i, j, ans, small, small_id, big, big_id;
	scanf("%d%d", &n, &k);
	for (i=0; i<n; i++)
	{
		scanf("%d", &ary[i].first);
	}
	for (i=0; i<n; i++)
	{
		scanf("%d", &ary[i].second);
	}
	sort(ary, ary+n);
	for (i=0; i<k; i++)
	{
		ed[i] = -1;
	}
	for (i=0, ans=0; i<n; i++)
	{
		for (j=0, small=1e9, big=-2; j<k; j++)
		{
			if (ed[j] < small)
			{
				small = ed[j];
				small_id = j;
			}
			if (ed[j] > big)
			{
				big = ed[j];
				big_id = j;
			}
		}
		if (ary[i].first > small)
		{
			++ans;
			ed[small_id] = ary[i].second;
		}
		else if (ary[i].second < big)
		{
			ed[big_id] = ary[i].second;
		}
	}
	printf("%d\n", ans);
	return 0;
}
