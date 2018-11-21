#include <stdio.h>
#include <math.h>

int n, m;
char str[100001];

long long calc(long long now, int times)
{
	long long temp;
	if(!times)
	{
		return 1;
	}
	if(times % 2)
	{
		return now * calc(now, times-1);
	}
	temp = calc(now, times/2);
	return temp * temp;
}

long long recursion(int times)
{
	long long temp;
	if(!times)
	{
		return 2;
	}
	if(times == 1)
	{
		return n;
	}
	if(times % 2)
	{
		return recursion(times/2) * recursion(times/2+1) - calc(m, times/2) * n;
	}
	temp = recursion(times/2);
	return temp * temp - 2 * calc(m, times/2);
}

int main()
{
	int o;
	while(gets(str))
	{
		if(sscanf(str, "%d%d%d", &n, &m, &o) == 2)
		{
			break;
		}
		printf("%lld\n", recursion(o));
	}
	return 0;
}
