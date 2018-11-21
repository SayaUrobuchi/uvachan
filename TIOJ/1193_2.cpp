#include <stdio.h>

int n, m, prime[80000], tbl[1000101];
long long temp, res;

long long recursion(long long p, long long q)
{
	if(q == 1)
	{
		return p;
	}
	if(q & 1)
	{
		return p * recursion(p, q-1) % m;
	}
	temp=recursion(p, q>>1);
	return temp*temp % m;
}

int main()
{
	int i, j, k, l;
	prime[0] = 2;
	for(i=3, l=1; i<1010; i+=2)
	{
		if(tbl[i] == 0)
		{
			prime[l++] = i;
			for(j=i*i, k=i+i; j<=1000010; j+=k)
			{
				tbl[j] = 1;
			}
		}
	}
	for(; i<=1000010; i+=2)
	{
		if(tbl[i] == 0)
		{
			prime[l++] = i;
		}
	}
	while(scanf("%d%d", &n, &m) == 2)
	{
		if(n == 0 && m == 0)
		{
			break;
		}
		if(n >= m)
		{
			printf("0\n");
			continue;
		}
		for(i=0, res=1; prime[i]<=n/prime[i]&&res; i++)
		{
			for(j=0, k=n; k; j+=(k/=prime[i]));
			res = res * recursion(prime[i], j) % m;
		}
		for(; prime[i]<=n&&res; i++)
		{
			res = res * recursion(prime[i], n/prime[i]) % m;
		}
		printf("%I64d\n", res);
	}
	return 0;
}
