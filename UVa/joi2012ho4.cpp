#include <iostream>
#include <vector>
using namespace std;

const int N = 6000;

int add[N], sub[N];
vector<int> vins[N];
vector<pair<int, int> > vera[N];

int main()
{
	int n, m, i, j, t, x, y, z, st, ans;
	scanf("%d%d", &n, &m);
	for (i=0; i<m; i++)
	{
		scanf("%d%d%d", &x, &y, &z);
		++z;
		vins[x].emplace_back(y);
		vera[x+z].emplace_back(y, z);
	}
	st = n;
	for (i=1, ans=0; i<=n; i++, st--)
	{
		for (j=0; j<vins[i].size(); j++)
		{
			++add[vins[i][j]];
			++sub[st + vins[i][j]+1];
		}
		for (j=0; j<vera[i].size(); j++)
		{
			--add[vera[i][j].first];
			--sub[st + vera[i][j].first + vera[i][j].second+1];
		}
		for (j=1, t=0; j<=i; j++)
		{
			t += add[j] - sub[st + j];
			ans += (t > 0);
		}
	}
	printf("%d\n", ans);
	return 0;
}