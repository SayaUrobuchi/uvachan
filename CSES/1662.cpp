#include <iostream>
using namespace std;

int tbl[262144];

int main()
{
	int n, i, t, sum;
	long long ans;
	while (scanf("%d", &n) == 1)
	{
		for (i=1; i<n; i++)
		{
			tbl[i] = 0;
		}
		tbl[0] = 1;
		for (i=0, ans=0, sum=0; i<n; i++)
		{
			scanf("%d", &t);
			sum = ((sum+t) % n + n) % n;
			ans += tbl[sum];
			++tbl[sum];
		}
		printf("%lld\n", ans);
	}
	return 0;
}

