#include <iostream>
#include <algorithm>
using namespace std;

int ary[1024];

int main()
{
	int cas, count, n, m, o, i;
	long long ans;
	cas = 0;
	scanf("%d", &count);
	while (count--)
	{
		scanf("%d%d%d", &o, &m, &n);
		for (i=0; i<n; i++)
		{
			scanf("%d", &ary[i]);
		}
		sort(ary, ary+n, greater<int>());
		for (i=0, ans=0; i<n; i++)
		{
			ans += (long long)ary[i] * (i/m+1);
		}
		printf("Case #%d: %lld\n", ++cas, ans);
	}
	return 0;
}
