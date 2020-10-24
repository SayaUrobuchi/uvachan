#include <iostream>
#include <vector>

std::vector<long long> v;

int main()
{
	long long n, i;
	while (scanf("%lld", &n) == 1)
	{
		v.clear();
		for (i=1; i*i<=n; i++)
		{
			if (n % i == 0)
			{
				printf("%lld\n", i);
				if (n != i*i)
				{
					v.emplace_back(n/i);
				}
			}
		}
		for (i=v.size()-1; i>=0; i--)
		{
			printf("%lld\n", v[i]);
		}
	}
	return 0;
}
