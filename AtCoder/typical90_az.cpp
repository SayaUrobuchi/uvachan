#include <iostream>
using namespace std;

const int M = 1e9+7;

int main()
{
	int n, i, j, t;
	long long sum, ans;
	while (scanf("%d", &n) == 1)
	{
		for (i=0, ans=1; i<n; i++)
		{
			for (j=0, sum=0; j<6; j++)
			{
				scanf("%d", &t);
				sum += t;
			}
			ans = (ans*sum) % M;
		}
		printf("%lld\n", ans);
	}
	return 0;
}
