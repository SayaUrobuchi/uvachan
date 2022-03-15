#include <iostream>
#include <algorithm>
using namespace std;
 
const int M = 1000000007;
 
int ary[200005];
 
int main()
{
	int n, i;
	long long ans;
	while (scanf("%d", &n) == 1)
	{
		for (i=0; i<n; i++)
		{
			scanf("%d", &ary[i]);
		}
		sort(ary, ary+n);
		for (i=0, ans=1; i<n; i++)
		{
			ans = (ans * max(0, ary[i]-i)) % M;
		}
		printf("%lld\n", ans);
	}
	return 0;
}
