#include <iostream>

long long c[128][128];

int main()
{
	int count, cas, n, i, j;
	long long ans;
	c[0][0] = 1;
	for (i=1; i<=100; i++)
	{
		c[i][0] = 1;
		for (j=1; j<=i; j++)
		{
			c[i][j] = c[i-1][j-1] + c[i-1][j];
		}
	}
	scanf("%d", &count);
	while (count--)
	{
		scanf("%d%d", &cas, &n);
		n >>= 1;
		i = n / 3;
		if ((n-i) & 1)
		{
			--i;
		}
		for (ans=0; i>=0; i-=2)
		{
			j = ((n-i)>>1);
			ans += c[i+j][i] * c[i+j][i];
		}
		printf("%d %lld\n", cas, ans);
	}
	return 0;
}
