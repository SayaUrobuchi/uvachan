#include <iostream>
#include <tuple>
#include <vector>
using namespace std;
using pp = pair<int, int>;

const int N = 16;
const int M = 16;

int people[N], travel[N];
int arrive[M][N];

int main()
{
	int n, m, o, i, j, k, u, v, d, c;
	bool is_opt;
	vector<vector<vector<pp> > > edg;
	scanf("%d%d%d", &n, &m, &o);
	edg.resize(m+1, vector<vector<pp>>(n+1));
	for (i=0; i<o; i++)
	{
		scanf("%d%d%d%d", &u, &v, &d, &c);
		edg[d][u].emplace_back(v, c);
	}
	for (i=0; i<n*m; i++)
	{
		scanf("%d%d%d", &u, &d, &c);
		arrive[d][u] = c;
	}
	for (i=1, is_opt=true; i<=m&&is_opt; i++)
	{
		for (j=1; j<=n; j++)
		{
			people[j] += arrive[i][j] + travel[j];
			travel[j] = 0;
		}
		for (j=1; j<=n&&is_opt; j++)
		{
			for (k=0; k<edg[i][j].size(); k++)
			{
				int nxt, cap;
				tie(nxt, cap) = edg[i][j][k];
				if (people[j] < cap)
				{
					is_opt = false;
					break;
				}
				people[j] -= cap;
				travel[nxt] += cap;
			}
		}
	}
	if (is_opt)
	{
		puts("optimal");
	}
	else
	{
		puts("suboptimal");
	}
	return 0;
}