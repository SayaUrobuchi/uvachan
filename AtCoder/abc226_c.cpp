#include <iostream>
#include <vector>
using namespace std;

const int N = 200005;

int tim[N];
bool used[N];
vector<int> v[N];

int main()
{
	int n, i, j;
	scanf("%d", &n);
	for (i=1; i<=n; i++)
	{
		int siz;
		scanf("%d%d", &tim[i], &siz);
		for (j=0; j<siz; j++)
		{
			int u;
			scanf("%d", &u);
			v[i].emplace_back(u);
		}
	}
	used[n] = true;
	long long ans = 0;
	for (i=n; i>=1; i--)
	{
		if (used[i])
		{
			ans += tim[i];
			for (j=0; j<v[i].size(); j++)
			{
				int nxt = v[i][j];
				used[nxt] = true;
			}
		}
	}
	printf("%lld\n", ans);
	return 0;
}
