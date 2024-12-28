#include <iostream>
using namespace std;

void calc(long long n, long long &m, long long i, long long &ans)
{
	int t = 0;
	while (m % i == 0)
	{
		m /= i;
		++t;
	}
	long long j;
	for (j=n; j<=t; j+=n)
	{
		ans *= i;
	}
}

int main()
{
	long long n, m, i;
	scanf("%lld%lld", &n, &m);
	long long ans = 1;
	for (i=2; i*i<=m; i++)
	{
		if (m % i == 0)
		{
			calc(n, m, i, ans);
		}
	}
	if (m > 1)
	{
		calc(n, m, m, ans);
	}
	printf("%lld\n", ans);
	return 0;
}