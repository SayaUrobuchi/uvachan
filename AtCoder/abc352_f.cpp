#include <iostream>
#include <vector>
#include <tuple>
using namespace std;
using pp = pair<int, int>;

const int N = 32;

int pos[N], id[N];
bool vis[N];
vector<int> bits;
vector<pp> conn[N];

void dfs(int cur, int p, vector<int> &path)
{
	int i;
	vis[cur] = true;
	path.emplace_back(cur);
	pos[cur] = p;
	for (i=0; i<conn[cur].size(); i++)
	{
		int nxt, cos;
		tie(nxt, cos) = conn[cur][i];
		if (!vis[nxt])
		{
			dfs(nxt, p+cos, path);
		}
	}
}

bool dfs2(int depth, int st, vector<bool> &vis)
{
	int i;
	if (depth == bits.size())
	{
		return true;
	}
	if (vis[st])
	{
		return false;
	}
	vis[st] = true;
	for (i=0; (bits[depth]<<i)<=st; i++)
	{
		int msk = (bits[depth] << i);
		if ((st & msk) == msk)
		{
			if (dfs2(depth+1, st&~msk, vis))
			{
				return true;
			}
		}
	}
	return false;
}

bool test(int lim, int st)
{
	vector<bool> vis(lim);
	return dfs2(1, lim&~st, vis);
}

int main()
{
	int n, m, i, j;
	scanf("%d%d", &n, &m);
	for (i=0; i<m; i++)
	{
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		conn[a].emplace_back(b, -c);
		conn[b].emplace_back(a, c);
	}
	for (i=1; i<=n; i++)
	{
		if (!vis[i])
		{
			vector<int> path;
			dfs(i, 0, path);
			int fix = n;
			for (j=0; j<path.size(); j++)
			{
				fix = min(fix, pos[path[j]]);
			}
			int stat = 0;
			for (j=0; j<path.size(); j++)
			{
				int idx = path[j];
				pos[idx] -= fix;
				stat |= (1 << pos[idx]);
				id[idx] = bits.size();
			}
			bits.emplace_back(stat);
		}
	}
	for (i=1; i<=n; i++)
	{
		swap(bits[0], bits[id[i]]);
		int multiple = 0;
		int p = -1;
		int allbit = (1 << n) - 1;
		for (j=0; j<n&&multiple<2&&(bits[0]<<j)<=allbit; j++)
		{
			if (test(allbit, bits[0]<<j))
			{
				p = j + 1 + pos[i];
				++multiple;
			}
		}
		int res = (multiple >= 2 ? -1 : p);
		printf("%d%c", res, " \n"[i==n]);
		swap(bits[0], bits[id[i]]);
	}
	return 0;
}
