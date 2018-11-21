#include <stdio.h>

long long recursion(int p, int q, int r, int s)
{
	int res;
	if(p == 0)
	{
		return 1;
	}
	if(q)
	{
		res = p * r;
	}
	else
	{
		res = (p-1) * r + s%(r*10) + 1;
	}
	return recursion(p/10, p%10, r*10, s) + res;
}

long long calc(int p)
{
	if(p == -1)
	{
		return 0;
	}
	else if(p == 0)
	{
		return 1;
	}
	return recursion(p/10, p%10, 1, p);
}

int main()
{
	int n, m, temp;
	while(scanf("%d%d", &n, &m) == 2)
	{
		if(n > m)
		{
			temp = n;
			n = m;
			m = temp;
		}
		printf("%I64d\n", calc(m) - calc(n-1));
	}
	return 0;
}
