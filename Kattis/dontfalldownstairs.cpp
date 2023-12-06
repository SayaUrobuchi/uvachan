#include <iostream>
using namespace std;

const int N = 1000005;

int ary[N];

int main()
{
	int n, i;
	long long ans;
	scanf("%d", &n);
	for (i=0; i<n; i++)
	{
		scanf("%d", &ary[i]);
	}
	ary[n] = 0;
	for (i=1, ans=0; i<=n; i++)
	{
		ans += max(0, ary[i-1] - ary[i] - 1);
	}
	printf("%lld\n", ans);
	return 0;
}
