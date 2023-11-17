#include <iostream>
#include <vector>
using namespace std;

const int N = 10;
const int N2N = (1 << N);
const int M = 1000;
const int MOD = 1e9 + 7;

int n;
int dp[M+1][N2N];
vector<int> v[N2N];

void dfs(vector<int> &v, int prev, int nxt, int pos)
{
	if (pos == n)
	{
		v.emplace_back(nxt);
		return;
	}
	if (prev & (1 << pos))
	{
		dfs(v, prev, nxt, pos+1);
	}
	else
	{
		dfs(v, prev, nxt | (1 << pos), pos+1);
		if (pos+1 < n && !(prev & (1 << (pos+1))))
		{
			dfs(v, prev, nxt, pos+2);
		}
	}
}

int main()
{
	int m, i, j, k, all;
	scanf("%d%d", &n, &m);
	all = (1 << n);
	for (i=0; i<all; i++)
	{
		dfs(v[i], i, 0, 0);
	}
	dp[0][0] = 1;
	for (i=1; i<=m; i++)
	{
		for (j=0; j<all; j++)
		{
			for (k=0; k<v[j].size(); k++)
			{
				int nxt = v[j][k];
				dp[i][nxt] = (dp[i][nxt] + dp[i-1][j]) % MOD;
			}
		}
	}
	printf("%d\n", dp[m][0]);
	return 0;
}
