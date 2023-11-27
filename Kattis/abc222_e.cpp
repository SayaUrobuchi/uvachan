#include <iostream>
#include <vector>
#include <tuple>
using namespace std;
using pp = pair<int, int>;

const int M = 128;
const int N = 1024;
const int K = 200005;
const int MOD = 998244353;

int id;
int ary[M], cnt[N], dp[K];
pp rng[N], par[N];
vector<pp> v[N];

void build(int cur, int p)
{
	int i;
	rng[cur].first = id;
	id += 10;
	for (i=0; i<v[cur].size(); i++)
	{
		int nxt = v[cur][i].first;
		if (nxt != p)
		{
			build(nxt, cur);
		}
		else
		{
			par[cur] = v[cur][i];
		}
	}
	rng[cur].second = id;
	id += 10;
}

int main()
{
	int n, m, o, i, j, a, b, cur, sum, ans;
	scanf("%d%d%d", &n, &m, &o);
	for (i=0; i<m; i++)
	{
		scanf("%d", &ary[i]);
	}
	for (i=1; i<n; i++)
	{
		scanf("%d%d", &a, &b);
		v[a].emplace_back(b, i);
		v[b].emplace_back(a, i);
	}
	id = 10;
	build(1, -1);
	cur = ary[0];
	for (i=1, sum=0; i<m; i++)
	{
		int tar = ary[i];
		int edg;
		while (cur != tar)
		{
			if (rng[tar].first < rng[cur].first
			 || rng[tar].second > rng[cur].second)
			{
				tie(cur, edg) = par[cur];
			}
			else
			{
				for (j=0; j<v[cur].size(); j++)
				{
					pp nxt = v[cur][j];
					if (nxt != par[cur] && rng[tar].first >= rng[nxt.first].first
					 && rng[tar].second <= rng[nxt.first].second)
					{
						tie(cur, edg) = nxt;
						break;
					}
				}
			}
			++sum;
			++cnt[edg];
		}
	}
	// R - B = K
	// R + B = sum
	// 2R = K + sum
	o += sum;
	ans = 0;
	if (!(o & 1) && o >= 0)
	{
		o >>= 1;
		dp[0] = 1;
		for (i=1; i<n; i++)
		{
			for (j=o; j>=cnt[i]; j--)
			{
				dp[j] = (dp[j] + dp[j-cnt[i]]) % MOD;
			}
		}
		ans = dp[o];
	}
	printf("%d\n", ans);
	return 0;
}
