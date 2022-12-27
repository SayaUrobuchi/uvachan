#include <iostream>
#include <algorithm>
using namespace std;

int ary[300005];

int main()
{
	int n, i;
	long long ans;
	scanf("%d", &n);
	for (i=0; i<n*3; i++)
	{
		scanf("%d", &ary[i]);
	}
	sort(ary, ary+n*3, greater<int>());
	for (i=0, ans=0; i<n; i++)
	{
		ans += ary[(i<<1)|1];
	}
	printf("%lld\n", ans);
	return 0;
}