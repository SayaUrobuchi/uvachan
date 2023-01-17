#include <iostream>
using namespace std;

int main()
{
	int ans;
	long long n;
	scanf("%lld", &n);
	for (ans=1; n!=1; ans++)
	{
		if (n & 1)
		{
			n = n+n+n + 1;
		}
		else
		{
			n >>= 1;
		}
	}
	printf("%d\n", ans);
	return 0;
}
