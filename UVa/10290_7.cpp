#include <stdio.h>
#include <math.h>
#include <unordered_map>

const int N = 1000020;
const int SQN = 1024;
const int PN = 1900000;

int m;
int prime[PN];
int tbl[N];
std::unordered_map<long long, int> dp;

int recurs(long long n, int ps)
{
	int i, c, *p;
	long long t = n;
	if (i=dp[n])
	{
		return i;
	}
	if (n == 1)
	{
		return dp[n] = 1;
	}
	if (t < N)
	{
		i = tbl[t];
		if (!i)
		{
			i = t;
		}
		for(t/=i, c=2; t%i==0; t/=i, c++);
		return dp[n]=c*recurs(t, 0);
	}
	for(p=prime+ps; (p-prime)<m&&(long long)*p**p<=t; p++)
	{
		if(t % *p == 0)
		{
			for(t/=*p, c=2; t%*p==0; t/=*p, c++);
			return dp[n]=c*recurs(t, p-prime+1);
		}
	}
	return dp[n] = 2;
}

int main()
{
	int i, j, k;
	long long n, t;
	for(i=3, m=0; i<SQN; i+=2)
	{
		if(tbl[i] == 0)
		{
			prime[m++] = i;
			for(j=i*i, k=i+i; j<N; j+=k)
			{
				tbl[j] = i;
			}
		}
	}
	for(; i<N; i+=2)
	{
		if(tbl[i] == 0)
		{
			prime[m++] = i;
		}
	}
	while(scanf("%lld", &n) == 1)
	{
		if (!n)
		{
			puts("1");
			continue;
		}
		for(t=n; !(t&1); t>>=1);
		printf("%d\n", recurs(t, 0));
	}
	return 0;
}
