#include <iostream>
using namespace std;

int ary[1048576];

int main()
{
	int n, i, pos;
	long long ans, sum, best;
	while (scanf("%d", &n) == 1)
	{
		for (i=0, ans=0; i<n; i++)
		{
			scanf("%d", &ary[i]);
			if (ary[i] == 0)
			{
				pos = i;
			}
			else
			{
				ans += ary[i] * (i+1);
			}
		}
		sum = ans;
		best = ans;
		for (i=pos+1; i<n; i++)
		{
			ans -= ary[i];
			best = max(best, ans);
		}
		ans = sum;
		for (i=pos-1; i>=0; i--)
		{
			ans += ary[i];
			best = max(best, ans);
		}
		printf("%lld\n", best);
	}
	return 0;
}
