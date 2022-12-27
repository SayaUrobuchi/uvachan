#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int ary[200005];

int main()
{
	int n, m, i, j, ans;
	vector<int> v;
	scanf("%d%d", &n, &m);
	for (i=0; i<n; i++)
	{
		scanf("%d", &ary[i]);
	}
	sort(ary, ary+n);
	for (i=0; i<n; i=j)
	{
		for (j=i+1; j<n&&ary[i]==ary[j]; j++);
		v.emplace_back(j-i);
	}
	sort(v.begin(), v.end());
	for (i=0, ans=0; i+m<v.size(); i++)
	{
		ans += v[i];
	}
	printf("%d\n", ans);
	return 0;
}