#include <iostream>
using namespace std;

long long dec(long long n, int k)
{
	long long res, t;
	for (res=0, t=1; n; n/=10, t*=k)
	{
		res += (n%10) * t;
	}
	return res;
}

int main()
{
	int k;
	long long a, b;
	while (scanf("%d", &k) == 1)
	{
		scanf("%lld%lld", &a, &b);
		printf("%lld\n", dec(a, k)*dec(b, k));
	}
	return 0;
}

