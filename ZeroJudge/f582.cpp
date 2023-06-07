#include <iostream>
#include <vector>
using namespace std;

const string key = "AUCG";
const int N = 1005;

int dp[N][4];
string str[N];
vector<int> v[N];

int recurs(int cur, int pos)
{
	int i, j, k;
	int res = 1e9;
	for (j=0; j<v[cur].size(); j++)
	{
		int nxt = v[cur][j];
		recurs(nxt, pos);
	}
	for (i=0; i<4; i++)
	{
		char tar = key[i];
		if (str[cur][pos] != '@' && str[cur][pos] != tar)
		{
			dp[cur][i] = 1e9;
		}
		else
		{
			dp[cur][i] = 0;
			for (j=0; j<v[cur].size(); j++)
			{
				int nxt = v[cur][j];
				int best = 1e9;
				for (k=0; k<4; k++)
				{
					best = min(best, dp[nxt][k] + (i != k));
				}
				dp[cur][i] += best;
			}
			res = min(dp[cur][i], res);
		}
	}
	return res;
}

int main()
{
	int n, m, i, a, b, root;
	char buf[105];
	scanf("%d%d", &n, &m);
	for (i=0; i<n; i++)
	{
		scanf("%d%d%s", &a, &b, buf);
		if (a == b)
		{
			root = a;
		}
		else
		{
			v[b].emplace_back(a);
		}
		str[a] = buf;
	}
	int ans = 0;
	for (i=0; i<m; i++)
	{
		ans += recurs(root, i);
	}
	printf("%d\n", ans);
	return 0;
}
