#include <iostream>
#include <algorithm>
using namespace std;

int ary[64];

int main()
{
	int n, k, i, ans;
	scanf("%d%d", &n, &k);
	for (i=0; i<n; i++)
	{
		scanf("%d", &ary[i]);
	}
	sort(ary, ary+n, greater<decltype(ary[0])>());
	for (i=0, ans=0; i<k; i++)
	{
		ans += ary[i];
	}
	printf("%d\n", ans);
	return 0;
}