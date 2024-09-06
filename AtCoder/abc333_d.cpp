#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int ROOT = 1;
const int N = 300005;

vector<int> conn[N];
int siz[N];

int travel(int cur, int par)
{
	int ret = 1;
	int i;
	for (i=0; i<conn[cur].size(); i++)
	{
		int nxt = conn[cur][i];
		if (nxt != par)
		{
			ret += travel(nxt, cur);
		}
	}
	return siz[cur] = ret;
}

int main()
{
	int n, i;
	scanf("%d", &n);
	for (i=1; i<n; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		conn[a].emplace_back(b);
		conn[b].emplace_back(a);
	}
	travel(ROOT, 0);
	int ans = 1;
	vector<int> v;
	for (i=0; i<conn[ROOT].size(); i++)
	{
		v.emplace_back(siz[conn[ROOT][i]]);
	}
	sort(v.begin(), v.end());
	for (i=0; i+1<v.size(); i++)
	{
		ans += v[i];
	}
	printf("%d\n", ans);
	return 0;
}
