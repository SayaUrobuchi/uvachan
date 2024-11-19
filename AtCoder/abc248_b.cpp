#include <iostream>
using namespace std;

int main()
{
	int b, k;
	long long a;
	scanf("%lld%d%d", &a, &b, &k);
	int ans = 0;
	while (a < b)
	{
		a *= k;
		++ans;
	}
	printf("%d\n", ans);
	return 0;
}