#include <iostream>
#include <algorithm>
using namespace std;

const int N = 200005;

int ary[N];

int main()
{
	int n, i;
	scanf("%d", &n);
	for (i=0; i<n; i++)
	{
		scanf("%d", &ary[i]);
	}
	sort(ary, ary+n);
	long long sum = ary[0];
	long long ans = 0;
	for (i=1; i<n; i++)
	{
		ans += ary[i]*1LL*i - sum;
		sum += ary[i];
	}
	printf("%lld\n", ans);
	return 0;
}
