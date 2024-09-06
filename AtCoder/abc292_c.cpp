#include <iostream>
using namespace std;

const int N = 200005;

int cnt[N];

int main()
{
	int n, i, j;
	scanf("%d", &n);
	for (i=1; i<=n; i++)
	{
		for (j=1; j*i<=n; j++)
		{
			++cnt[i*j];
		}
	}
	long long ans = 0;
	for (i=1; i<n; i++)
	{
		ans += cnt[i] * cnt[n-i];
	}
	printf("%lld\n", ans);
	return 0;
}
