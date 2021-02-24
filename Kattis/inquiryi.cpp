#include<iostream>
using namespace std;

int ary[1048576];

int main()
{
	int n, i;
	long long sum, ans, left;
	while (scanf("%d", &n) == 1)
	{
		for (i=0, sum=0; i<n; i++)
		{
			scanf("%d", &ary[i]);
			sum += ary[i];
		}
		ans = 0;
		for (i=0, left=0; i<n; i++)
		{
			left += ary[i]*ary[i];
			sum -= ary[i];
			if (left * sum > ans)
			{
				ans = left * sum;
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}
