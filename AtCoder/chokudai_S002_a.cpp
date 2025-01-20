#include <iostream>
using namespace std;

int main()
{
	int n, i;
	scanf("%d", &n);
	for (i=0; i<n; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		long long ans = a * 1LL * b;
		printf("%lld\n", ans);
	}
	return 0;
}
