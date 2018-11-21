#include <stdio.h>

int n, k;

long long recursion(int pre, int now, long long last)
{
	long long temp;
	if(now < k)
	{
		temp = 0;
	}
	else if(now == k)
	{
		temp = n % last + 1;
	}
	else
	{
		temp = last;
	}
	if(!pre)
	{
		if(k)
		{
			return temp;
		}
		else
		{
			return 0;
		}
	}
	temp += (pre - !k) * last;
	return temp + recursion(pre/10, pre%10, last*10);
}

int main()
{
	while(scanf("%d%d", &n, &k) == 2)
	{
		printf("%I64d\n", recursion(n/10, n%10, 1));
	}
	return 0;
}
