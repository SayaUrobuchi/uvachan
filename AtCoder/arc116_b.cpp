#include <iostream>
#include <algorithm>
using namespace std;

const int N = 200005;
const int MOD = 998244353;

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
	int ans = 0;
	int sum = 0;
	for (i=n-1; i>=0; i--)
	{
		ans = (ans + ary[i] * 1LL * (sum + ary[i])) % MOD;
		sum = (sum * 2LL + ary[i]) % MOD;
	}
	printf("%d\n", ans);
	return 0;
}
