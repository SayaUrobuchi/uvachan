#include <iostream>

int tim[1024], buf[1024];

int main()
{
	int n, m, i;
	long long last, st;
	while (scanf("%d%d", &n, &m) == 2)
	{
		for (i=0; i<n; i++)
		{
			scanf("%d", &tim[i]);
		}
		for (i=1; i<n; i++)
		{
			scanf("%d", &buf[i]);
		}
		for (i=0, last=0, st=0; i<n; i++)
		{
			last = std::max((long long)tim[i] * m + st, last+tim[i]);
			st += tim[i];
		}
		printf("%lld\n", last);
	}
	return 0;
}
