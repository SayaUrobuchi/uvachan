#include <iostream>
#include <vector>
#include <tuple>
using namespace std;
using pp = pair<int, int>;

const int N = 2505;

int from[N];
long long dis[N];
bool used[N];
vector<int> res;
vector<pp> edg[N];

int main()
{
	int n, m, i, j, k, a, b, c, t;
	bool updated;
	scanf("%d%d", &n, &m);
	for (i=0; i<m; i++)
	{
		scanf("%d%d%d", &a, &b, &c);
		edg[a].emplace_back(b, c);
	}
	for (k=0, updated=true; k<n&&updated; k++)
	{
		updated = false;
		for (i=1; i<=n; i++)
		{
			for (j=0; j<edg[i].size(); j++)
			{
				int nxt, cos;
				tie(nxt, cos) = edg[i][j];
				if (dis[nxt] > dis[i] + cos)
				{
					dis[nxt] = dis[i] + cos;
					t = nxt;
					from[nxt] = i;
					updated = true;
				}
			}
		}
	}
	if (!updated)
	{
		puts("NO");
	}
	else
	{
		puts("YES");
		i = t;
		fprintf(stderr, ". %d\n", t);
		for (j=i; !used[j]; j=from[j])
		{
			used[j] = true;
			res.emplace_back(j);
		}
		//printf(".. %d %d\n", j, from[j]);
		for (i=res.size()-1; res[i]!=j; i--)
		//for (i=res.size()-1; i>=0; i--)
		{
			printf("%d ", res[i]);
		}
		printf("%d %d\n", j, res.back());
	}
	return 0;
}
