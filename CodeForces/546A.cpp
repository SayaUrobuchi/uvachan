#include <iostream>
using namespace std;

int main()
{
	int n, w, k;
	scanf("%d%d%d", &k, &n, &w);
	long long need = k * (1LL+w) * w / 2;
	long long ans = max(0LL, need-n);
	printf("%lld\n", ans);
	return 0;
}
