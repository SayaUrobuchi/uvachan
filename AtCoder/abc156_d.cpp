#include <iostream>
#include <vector>
using namespace std;

const int N = 200005;
const int MOD = 1000000007;

int ary[N];
bool used[N];
vector<int> prime;

int ffa(int a, int b)
{
	int ret = 1;
	int t;
	for (t=a; b; t=(t*1LL*t)%MOD, b>>=1)
	{
		if (b & 1)
		{
			ret = (ret * 1LL * t) % MOD;
		}
	}
	return ret;
}

int c(int a, int b)
{
	int i, j;
	for (i=0; i<b; i++)
	{
		ary[i] = a-b+i+1;
	}
	for (i=0; prime[i]<=b; i++)
	{
		int p = prime[i];
		int t = 0;
		for (j=b; j; t+=j/=p);
		int st = a-b+1;
		int idx = (p - st%p) % p;
		while (t)
		{
			if (ary[idx] % p == 0)
			{
				ary[idx] /= p;
				--t;
			}
			else
			{
				idx += p;
			}
		}
	}
	int ret = 1;
	for (i=0; i<b; i++)
	{
		ret = (ret * 1LL * ary[i]) % MOD;
	}
	return ret;
}

int main()
{
	int n, a, b, i, j;
	for (i=2; i<N; i++)
	{
		if (!used[i])
		{
			prime.emplace_back(i);
		}
		for (j=0; i*prime[j]<N; j++)
		{
			used[i*prime[j]] = true;
			if (i % prime[j] == 0)
			{
				break;
			}
		}
	}
	scanf("%d%d%d", &n, &a, &b);
	int ans = ffa(2, n);
	ans = (ans - 1 + MOD) % MOD;
	ans = (ans - c(n, a) + MOD) % MOD;
	ans = (ans - c(n, b) + MOD) % MOD;
	printf("%d\n", ans);
	return 0;
}
