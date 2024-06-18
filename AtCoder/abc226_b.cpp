#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> v[200005];

int main()
{
	int n, i, j;
	scanf("%d", &n);
	for (i=0; i<n; i++)
	{
		int t;
		scanf("%d", &t);
		for (j=0; j<t; j++)
		{
			int u;
			scanf("%d", &u);
			v[i].emplace_back(u);
		}
	}
	sort(v, v+n);
	int ans = unique(v, v+n) - v;
	printf("%d\n", ans);
	return 0;
}
