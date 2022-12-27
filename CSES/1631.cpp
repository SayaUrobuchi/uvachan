#include <iostream>
using namespace std;

int main()
{
	int n, i, t, mx;
	long long sum;
	while (scanf("%d", &n) == 1)
	{
		for (i=0, sum=0, mx=0; i<n; i++)
		{
			scanf("%d", &t);
			sum += t;
			mx = max(mx, t);
		}
		printf("%lld\n", max(sum, (long long)mx<<1));
	}
	return 0;
}

