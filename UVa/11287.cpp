#include <stdio.h>
#include <math.h>

int n, m;

int recursion(int now, int times)
{
	long long temp;
	if(!times)
	{
		return 1;
	}
	if(times % 2)
	{
		return ((long long)now * recursion(now, times-1)) % n;
	}
	else
	{
		temp = recursion(now, times/2);
		temp *= temp;
		return temp % n;
	}
}

int main()
{
	int i, s;
	while(scanf("%d%d", &n, &m) == 2)
	{
		if(!n && !m)
		{
			break;
		}
		i = -1;
		s = 2;
		if(n % 2)
		{
			s = sqrt(n) + 1;
			for(i=3; i<s; i+=2)
			{
				if(!(n % i))
				{
					break;
				}
			}
		}
		if(i >= s)
		{
			puts("no");
		}
		else
		{
			m %= n;
			if(recursion(m, n) == m)
			{
				printf("yes\n");
			}
			else
			{
				printf("no\n");
			}
		}
	}
	return 0;
}
