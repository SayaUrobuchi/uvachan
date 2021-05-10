#include <iostream>

int ary[1048576];

int main()
{
	int n, i, best;
	long long sum;
	while (scanf("%d", &n) == 1)
	{
		for (i=0, sum=0, best=0; i<n; i++)
		{
			scanf("%d", &ary[i]);
			sum += ary[i];
			best = std::max(best, ary[i]);
		}
		printf("%lld\n", std::max((long long)(best<<1), sum));
	}
	return 0;
}
