#include <iostream>

using bigint = __int128_t;

int main()
{
	int count, n, i;
	long long t;
	bigint sum;
	scanf("%d", &count);
	while (count--)
	{
		scanf("%d", &n);
		for (i=0, sum=0; i<n; i++)
		{
			scanf("%lld", &t);
			sum += t;
		}
		puts(sum%n ? "NO" : "YES");
	}
	return 0;
}
