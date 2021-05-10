#include <iostream>

int main()
{
	int i;
	long long n, m, ans, j, r;
	while (scanf("%lld%lld", &n, &m) == 2)
	{
		for (i=1, j=1, ans=0, r=m-(n-1); r&&i<n; i++)
		{
			ans += j;
			++j;
			if (i-1 > r)
			{
				j += r;
				r = 0;
			}
			else
			{
				j += i-1;
				r -= i-1;
			}
		}
		if (i < n)
		{
			ans += (j+(j+n-i-1))*(n-i)/2;
		}
		printf("%lld\n", ans);
	}
	return 0;
}
