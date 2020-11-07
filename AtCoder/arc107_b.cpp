#include <iostream>

long long calc(int t, int n)
{
	return (t-1>n?n:t-1) - (t-n<1?1:t-n) + 1;
}

int main()
{
	int n, m, i, t, n2;
	long long ans;
	while (scanf("%d%d", &n, &m) == 2)
	{
		n2 = n+n;
		for (i=2, ans=0; i<=n2; i++)
		{
			t = i + m;
			if (t >= 2 && t <= n2)
			{
				ans += calc(t, n) * calc(i, n);
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}
