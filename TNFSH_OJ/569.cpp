#include<iostream>
#include <vector>
using namespace std;

const int N = 1024;
const int M = 1000000007;

int ucnt;
int id[N];
int tbl[N][N], used[N][N], dp[N][N];
vector<int> rr[N][N], v[N];

int recurs(int p, int q)
{
	int i, j, a, b;
	if (used[p][q] == ucnt)
	{
		return dp[p][q];
	}
	used[p][q] = ucnt;
	dp[p][q] = 1;
	for (i=0; i<v[p].size(); i++)
	{
		a = v[p][i];
		for (j=0; j<rr[q][id[a]].size(); j++)
		{
			b = rr[q][id[a]][j];
			dp[p][q] = (dp[p][q]+recurs(a, b)) % M;
		}
	}
	//printf(".. %d %d : %d\n", p, q, dp[p][q]);
	return dp[p][q];
}

int main() {
	int n, m, i, j, ans;
	while (scanf("%d%d", &n, &m) == 2)
	{
		for (i=0; i<n; i++)
		{
			scanf("%d", &id[i]);
			v[i].clear();
			for (j=1; j<=1000; j++)
			{
				rr[i][j].clear();
			}
		}
		for (i=0; i<n; i++)
		{
			for (j=0; j<n; j++)
			{
				scanf("%d", &tbl[i][j]);
				if (tbl[i][j])
				{
					rr[i][id[j]].push_back(j);
					v[j].push_back(i);
				}
			}
		}
		++ucnt;
		for (i=0, ans=0; i<n; i++)
		{
			ans = (ans+recurs(i, i)) % M;
			//printf("!? %d %d: %d\n", i, i, recurs(i, i));
			for (j=0; j<rr[i][id[i]].size(); j++)
			{
				ans = (ans+recurs(i, rr[i][id[i]][j])) % M;
				//printf("!? %d %d : %d\n", i, rr[i][id[i]][j], recurs(i, rr[i][id[i]][j]));
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}

