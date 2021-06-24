#include <iostream>

long long ary[100005];

int main()
{
	int n;
	long long m;
	ary[1] = ary[2] = 1;
	for (n=3; n<100005; n++)
	{
		ary[n] = std::min(1LL<<61, ary[n-1]+ary[n-2]);
	}
	while (scanf("%d%lld", &n, &m) == 2)
	{
		for (; n>2; )
		{
			//printf("%lld vs %lld\n", m, ary[n-2]);
			if (m <= ary[n-2])
			{
				n -= 2;
			}
			else
			{
				m -= ary[n-2];
				--n;
			}
		}
		puts(n == 1 ? "N" : "A");
	}
	return 0;
}
