#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

const int N = 1000005;

bool used[N];

int main()
{
	long long n;
	int i, j;
	scanf("%lld", &n);
	vector<int> prime;
	for (i=2; i<N; i++)
	{
		if (!used[i])
		{
			prime.emplace_back(i);
		}
		for (j=0; j<prime.size()&&i*prime[j]<N; j++)
		{
			used[i*prime[j]] = true;
			if (i % prime[j] == 0)
			{
				break;
			}
		}
	}
	int ans = 0;
	for (i=0; i<prime.size(); i++)
	{
		long long t = prime[i] * 1LL * prime[i];
		if (t > n)
		{
			break;
		}
		for (j=i+1; j<prime.size()&&t*prime[j]<=n/prime[j]/prime[j]; j++)
		{
			long long u = t * prime[j];
			int idx = upper_bound(prime.begin()+j+1, prime.end(), (int)sqrt(n/u)) - prime.begin();
			ans += max(0, idx-(j+1));
		}
	}
	printf("%d\n", ans);
	return 0;
}
