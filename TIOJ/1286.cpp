#include <stdio.h>

long long calc(long long p, long long q)
{
	long long temp;
	if(q == 0)
	{
		return 1;
	}
	if(q % 2)
	{
		return ((p % 1000000) * (calc(p, q-1) % 1000000)) % 1000000; 
	}
	temp = calc(p, q>>1) % 1000000;
	return (temp * temp) % 1000000;
}

int main()
{
	long long a, b, c, d, ans;
	while(scanf("%I64d%I64d%I64d%I64d", &a, &b, &c, &d) == 4)
	{
		for(ans=0; a<=d; a+=b)
		{
			ans += calc(a, c);
			ans %= 1000000;
		}
		printf("%I64d\n", ans);
	}
	return 0;
}
