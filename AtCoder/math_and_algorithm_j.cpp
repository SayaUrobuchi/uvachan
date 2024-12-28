#include <iostream>
using namespace std;

int main()
{
	int n, i;
	scanf("%d", &n);
	long long ans = 1;
	for (i=1; i<=n; i++)
	{
		ans *= i;
	}
	printf("%lld\n", ans);
	return 0;
}
