#include <iostream>
using namespace std;

int main()
{
	int n, i;
	scanf("%d", &n);
	long long ans = 0;
	long long best = -1e9;
	long long sum = 0;
	long long st = 0;
	for (i=0; i<n; i++)
	{
		int t;
		scanf("%d", &t);
		sum += t;
		best = max(best, sum);
		ans = max(ans, st + best);
		st += sum;
	}
	printf("%lld\n", ans);
	return 0;
}
