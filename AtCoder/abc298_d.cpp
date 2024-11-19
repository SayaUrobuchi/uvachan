#include <iostream>
#include <vector>
using namespace std;

const int N = 600005;
const int MOD = 998244353;

long long pw[N];

int main()
{
	int n, i;
	scanf("%d", &n);
	long long t = 1;
	int head = 0;
	vector<int> v(1, 1);
	pw[0] = 1;
	for (i=1; i<=n; i++)
	{
		int cmd;
		scanf("%d", &cmd);
		pw[i] = pw[i-1] * 10 % MOD;
		if (cmd == 1)
		{
			int x;
			scanf("%d", &x);
			t = ((t * 10) + x) % MOD;
			v.emplace_back(x);
		}
		else if (cmd == 2)
		{
			t = (t - v[head] * pw[v.size() - head - 1] % MOD + MOD) % MOD;
			++head;
		}
		else
		{
			printf("%lld\n", t);
		}
	}
	return 0;
}
