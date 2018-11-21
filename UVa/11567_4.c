#include <stdio.h>

int id, res;
long long int s;

int idfs(int c, long long int n, int d, int f)
{
	if(n == s)
	{
		return 1;
	}
	if(n > s)
	{
		if(n - (1ll<<d) > s + (1ll<<d))
		{
			return 0;
		}
		if(c + 1 <= id)
		{
			if(idfs(c+1, n-(1ll<<d), d-1, 0))
			{
				return 1;
			}
		}
	}
	else
	{
		if(n + (1ll<<d) < s - (1ll<<d))
		{
			return 0;
		}
		if(n + (1ll<<d) <= s)
		{
			f = 0;
		}
		if(c + 1 + f <= id)
		{
			if(idfs(c+1+f, n+(1ll<<d), d-1, 0))
			{
				return 1;
			}
		}
	}
	if(idfs(c, n, d-1, f))
	{
		return 1;
	}
	return 0;
}

int main()
{
	long long t;
	int i;
	while(scanf("%lld", &s) == 1)
	{
		for(t=s, i=0; t>1; t>>=1, i++);
		for(id=0; ; id++)
		{
			if(idfs(0, 0ll, 31, 1))
			{
				break;
			}
		}
		printf("%d\n", id+i);
	}
	return 0;
}

