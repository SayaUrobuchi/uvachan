#include <stdio.h>

int main()
{
	int i, ans;
	long long n, t, u, j;
	while (scanf("%lld", &n) == 1)
	{
		if (!n)
		{
			break;
		}
		ans = 0;
		for (i=1, t=(n<<1)-1, u=1; u*u<=t; i++, t++, u+=2)
		{
			if (!(t % u))
			{
				++ans;
				if (i != t/u)
				{
					++ans;
				}
			}
		}
		printf("%lld %d\n", n, ans);
	}
	return 0;
}
