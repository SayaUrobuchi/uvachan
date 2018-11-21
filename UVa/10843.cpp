#include <stdio.h>

long long recursion(int now, int times)
{
	long long temp;
	if(times < 1)
	{
		return 1;
	}
	else if(times == 1)
	{
		return now;
	}
	else if(times % 2)
	{
		return (now * recursion(now, times-1)) % 2000000011;
	}
	temp = recursion(now, times/2);
	return (temp * temp) % 2000000011;
}

int main()
{
	int cas, count, n, i, j;
	cas = 0;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d", &n);
		printf("Case #%d: %lld\n", ++cas, recursion(n, n-2));
	}
	return 0;
}
