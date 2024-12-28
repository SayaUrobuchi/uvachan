#include <iostream>
using namespace std;

int main()
{
	int n, i;
	scanf("%d", &n);
	long long ans = 0;
	for (i=1; i<=n; i++)
	{
		if (i % 3 && i % 5)
		{
			ans += i;
		}
	}
	printf("%lld\n", ans);
	return 0;
}
