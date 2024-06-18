#include <iostream>
#include <vector>
using namespace std;

const int N = 200005;
const int M = 998244353;

bool used[N];
vector<int> v[N];

void dfs(int cur, int &nod, int &deg)
{
	int i;
	used[cur] = true;
	++nod;
	deg += v[cur].size();
	for (i=0; i<v[cur].size(); i++)
	{
		int nxt = v[cur][i];
		if (!used[nxt])
		{
			dfs(nxt, nod, deg);
		}
	}
}

int main()
{
	int n, m, i;
	scanf("%d%d", &n, &m);
	for (i=0; i<m; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		v[a].emplace_back(b);
		v[b].emplace_back(a);
	}
	int b = 0;
	bool gg = false;
	for (i=1; i<=n; i++)
	{
		if (!used[i])
		{
			int nod, deg;
			nod = deg = 0;
			dfs(i, nod, deg);
			if ((nod<<1) == deg)
			{
				++b;
			}
			else
			{
				gg = true;
			}
		}
	}
	if (gg)
	{
		puts("0");
	}
	else
	{
		long long ans = 1;
		long long t = 2;
		for (; b; b>>=1)
		{
			if (b & 1)
			{
				ans = (ans * t) % M;
			}
			t = (t * t) % M;
		}
		printf("%lld\n", ans);
	}
	return 0;
}
