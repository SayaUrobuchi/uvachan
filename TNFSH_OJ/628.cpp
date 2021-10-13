#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int ary[1048576][8], rnk[1048576];
vector<int> v[1024];

int main()
{
	int n, m, i, j, k, t;
	ios::sync_with_stdio(0);
	cin.tie(0);
	while (cin >> n >> m >> k)
	{
		for (i=1; i<=m; i++)
		{
			v[i].clear();
		}
		for (i=1; i<=n; i++)
		{
			cin >> rnk[i];
		}
		for (i=1; i<=n; i++)
		{
			for (j=0; j<5; j++)
			{
				cin >> ary[i][j];
			}
		}
		for (i=1; i<=n; i++)
		{
			t = rnk[i];
			for (j=0; j<5; j++)
			{
				if (v[ary[t][j]].size() < k)
				{
					v[ary[t][j]].emplace_back(t);
					break;
				}
			}
		}
		for (i=1; i<=m; i++)
		{
			cout << v[i].size();
			sort(v[i].begin(), v[i].end());
			for (j=0; j<v[i].size(); j++)
			{
				cout << " " << v[i][j];
			}
			cout << "\n";
		}
	}
	return 0;
}
