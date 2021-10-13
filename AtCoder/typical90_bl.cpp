#include <iostream>
using namespace std;

long long ary[131072], diff[131072];

int main()
{
	int n, m, i, a, b, c;
	long long sum;
	while (scanf("%d%d", &n, &m) == 2)
	{
		for (i=1, sum=0; i<=n; i++)
		{
			scanf("%lld", &ary[i]);
			diff[i] = ary[i] - ary[i-1];
			sum += abs(diff[i]);
		}
		sum -= abs(diff[1]);
		for (i=0; i<m; i++)
		{
			scanf("%d%d%d", &a, &b, &c);
			if (a > 1)
			{
				sum -= abs(diff[a]);
				diff[a] += c;
				sum += abs(diff[a]);
			}
			if (b < n)
			{
				sum -= abs(diff[b+1]);
				diff[b+1] -= c;
				sum += abs(diff[b+1]);
			}
			//printf("ans: ");
			printf("%lld\n", sum);
		}
	}
	return 0;
}
