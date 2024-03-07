#include <iostream>
#include <vector>
#include <tuple>
using namespace std;
using pp = pair<int, int>;

const int N = 1005;

bool has_leaf[N];
vector<pp> v[N];

pp rec(int cur)
{
	int ret = 0;
	int ret_go = 0;
	int i;
	for (i=0; i<v[cur].size(); i++)
	{
		int nxt, dis;
		tie(nxt, dis) = v[cur][i];
		int res, go;
		tie(res, go) = rec(nxt);
		if (go || has_leaf[nxt])
		{
			ret += res + (dis << 1);
			ret_go = 1;
		}
	}
	return make_pair(ret, ret_go);
}

int main()
{
	int n, m, i;
	scanf("%d%d", &n, &m);
	for (i=1; i<n; i++)
	{
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		v[a].emplace_back(b, c);
	}
	for (i=0; i<m; i++)
	{
		int t;
		scanf("%d", &t);
		has_leaf[t] = true;
	}
	printf("%d\n", rec(0).first);
	return 0;
}
