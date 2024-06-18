#include <iostream>
#include <algorithm>
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
	int sum = 0;
	int dis = diff[n];
	int best = 0;
	for (i=n+1, j=n; i>=1; i--)
	{
		if (j + 1 >= i)
		{
			j = i - 1;
		}
		for (; j>=0&&pre[j]+sum>m; j--);
		int idx = -(diff[n] - diff[i-1]) + n2;
		while (v[idx].size() && v[idx].back() > j)
		{
			v[idx].pop_back();
		}
		if (v[idx].size())
		{
			int r = v[idx].back();
			best = max(best, sum + pre[r]);
		}
		sum += ary[i-1];
	}
	cout << best << "\n";
	return 0;
}
