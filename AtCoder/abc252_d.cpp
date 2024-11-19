#include <iostream>
using namespace std;

const int N = 200005;

int tbl[N];

int main()
{
	int n, i;
	scanf("%d", &n);
	for (i=0; i<n; i++)
	{
		int t;
		scanf("%d", &t);
		++tbl[t];
	}
	long long ans = n * 1LL * n * n;
	for (i=0; i<N; i++)
	{
		ans -= tbl[i] * 3LL * tbl[i] * (n-tbl[i]);
		ans -= tbl[i] * 1LL * tbl[i] * tbl[i];
	}
	printf("%lld\n", ans/6);
	return 0;
}
