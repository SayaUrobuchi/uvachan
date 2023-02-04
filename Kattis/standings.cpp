#include <iostream>
#include <algorithm>
using namespace std;

const int N = 100005;

int ary[N];

int main()
{
	int count, n, i;
	long long ans;
	scanf("%d", &count);
	while (count--)
	{
		scanf("%d", &n);
		for (i=0; i<n; i++)
		{
			scanf("%*s%d", &ary[i]);
		}
		sort(ary, ary+n);
		for (i=0, ans=0; i<n; i++)
		{
			ans += abs(ary[i] - (i+1));
		}
		printf("%lld\n", ans);
	}
	return 0;
}
