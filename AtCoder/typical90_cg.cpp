#include <iostream>
using namespace std;

int main()
{
	long long n, m, i, j, ans;
	while (scanf("%lld", &n) == 1)
	{
		for (i=1, ans=0; i*i*i<=n; i++)
		{
			if (n % i == 0)
			{
				m = n / i;
				for (j=i; j*j<=m; j++)
				{
					if (m % j == 0)
					{
						++ans;
					}
				}
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}
