#include <iostream>
#include <vector>
using namespace std;

const int N = 300005;
const int N4 = (N << 2);

int ary[N], pre[N];
int diff[N4], nxt[N4];
vector<int> v[N4];

int main()
{
	int n, m, i, j, k;
	cin >> n >> m;
	int n2 = (n << 1);
	int odd = 0;
	int even = 0;
	v[n2].emplace_back(0);
	for (i=1; i<=n; i++)
	{
		cin >> ary[i];
		pre[i] = pre[i-1] + ary[i];
		if (ary[i] & 1)
		{
			++odd;
		}
		else
		{
			++even;
		}
		diff[i] = odd - even;
		v[diff[i]+n2].emplace_back(i);
	}
	int sum = pre[n];
	int dis = diff[n];
	int best = 0;
	for (i=1, j=1; i<=n; i++)
	{
		for (j=max(j, i-1); j<=n&&pre[j]-pre[i-1]<sum-m; j++);
		if (j <= n)
		{
			// idx - diff[i-1] == dis
			// idx = dis + diff[i-1]
			int idx = dis + diff[i-1] + n2;
			for (k=nxt[idx]; k<v[idx].size()&&v[idx][k]<j; ++k);
			if (k < v[idx].size())
			{
				int r = v[idx][k];
				best = max(best, sum - (pre[r] - pre[i-1]));
			}
			nxt[idx] = k;
		}
	}
	cout << best << "\n";
	return 0;
}
