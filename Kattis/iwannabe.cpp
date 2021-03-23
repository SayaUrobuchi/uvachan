#include <iostream>
#include <unordered_set>
#include <algorithm>
using namespace std;

int idx;
int ii[1048576];
long long ary[1048576], bry[1048576], cry[1048576];

bool comp(long long a, long long b)
{
	if (idx == 0)
	{
		return ary[a] > ary[b];
	}
	if (idx == 1)
	{
		return bry[a] > bry[b];
	}
	return cry[a] > cry[b];
}

int main()
{
	int n, m, i;
	unordered_set<int> sss;
	while (scanf("%d%d", &n, &m) == 2)
	{
		for (i=0; i<n; i++)
		{
			scanf("%lld%lld%lld", &ary[i], &bry[i], &cry[i]);
			ii[i] = i;
		}
		sss.clear();
		for (idx=0; idx<3; idx++)
		{
			sort(ii, ii+n, comp);
			for (i=0; i<m; i++)
			{
				sss.insert(ii[i]);
			}
		}
		printf("%d\n", sss.size());
	}
	return 0;
}
