#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 2005;

int ary[N];

int main()
{
	int n, m, i, j, t, ans, best;
	vector<int> v;
	scanf("%d%d", &n, &m);
	for (i=0; i<n; i++)
	{
		scanf("%d", &ary[i]);
	}
	for (i=0; i<m; i++)
	{
		scanf("%d", &t);
		for (j=0; j<n&&ary[j]<t; j++)
		{
			v.emplace_back(t-ary[j]);
		}
	}
	sort(v.begin(), v.end());
	for (i=0, best=0; i<v.size(); i=j)
	{
		for (j=i+1; j<v.size()&&v[j]==v[i]; j++);
		//printf("diff %d has %d pairs\n", v[i], j-i);
		if (j-i > best)
		{
			best = j - i;
			ans = v[i];
		}
	}
	printf("%d\n", ans);
	return 0;
}
