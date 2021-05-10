#include <iostream>
#include <cmath>

long long cc[32][32];

int main()
{
	int count, a, b, c, d, e, i, j;
	long long son, mon, ans;
	cc[0][0] = 1;
	for (i=1; i<=20; i++)
	{
		cc[i][0] = 1;
		for (j=1; j<=i; j++)
		{
			cc[i][j] = cc[i-1][j-1] + cc[i-1][j];
		}
	}
	scanf("%d", &count);
	while (count--)
	{
		scanf("%d%d%d%d%d", &a, &b, &c, &d, &e);
		--a;
		if (a)
		{
			for (i=0, son=1, mon=1; i<c; i++)
			{
				son *= b-a;
				mon *= b;
			}
			for (; i<d; i++)
			{
				if (a)
				{
					son *= a;
				}
				mon *= b;
			}
			for (i=c, ans=0; i<=d; ans+=son*cc[d][i], ++i, son*=b-a, a?son/=a:a);
			//printf("%lld %lld\n", ans, mon);
		}
		else
		{
			ans = mon = 1;
		}
		ans *= e;
		if (ans > mon)
		{
			puts("yes");
		}
		else
		{
			puts("no");
		}
	}
	return 0;
}
