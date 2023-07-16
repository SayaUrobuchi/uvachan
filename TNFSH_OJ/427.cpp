#include <iostream>
using namespace std;

const int PN = 1000000;

int tbl[PN+5], prime[PN];
long long ans[PN+5];

int phi(int t)
{
	int i, res;
	for (i=t, res=t; i>1; )
	{
		int p = tbl[i];
		res = (long long)res * (p-1) / p;
		while (i % p == 0)
		{
			i /= p;
		}
	}
	return res;
}

int main()
{
	int n, i, j, k;
	for (i=2, j=0; i<=PN; i++)
	{
		if (!tbl[i])
		{
			tbl[i] = i;
			prime[j++] = i;
		}
		for (k=0; k<j&&i*prime[k]<=PN; k++)
		{
			tbl[i*prime[k]] = prime[k];
			if (i % prime[k] == 0)
			{
				break;
			}
		}
	}
	ans[0] = 0;
	ans[1] = 3;
	for (i=2; i<=PN; i++)
	{
		ans[i] = ans[i-1] + phi(i) * 2;
	}
	while (scanf("%d", &n) == 1)
	{
		printf("%lld\n", ans[n]);
	}
	return 0;
}
