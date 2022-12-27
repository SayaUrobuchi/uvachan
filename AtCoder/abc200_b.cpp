#include <iostream>
using namespace std;

int main()
{
	int m;
	long long n;
	while (scanf("%lld%d", &n, &m) == 2)
	{
		while (m--)
		{
			if (n % 200)
			{
				n = n*1000 + 200;
			}
			else
			{
				n /= 200;
			}
		}
		printf("%lld\n", n);
	}
	return 0;
}

