#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
using vv = pair<int, pair<int, int> >;

int ary[1048576];
vector<vv> v[1048576];

double recurs(int cur)
{
	int i;
	double need, val;
	if (ary[cur] != -1)
	{
		return ary[cur];
	}
	for (i=0, need=0; i<v[cur].size(); i++)
	{
		vv t = v[cur][i];
		val = recurs(t.first);
		if (t.second.second)
		{
			val = sqrt(val);
		}
		val *= 100.0 / t.second.first;
		//printf(".. %d => %.10lf\n", t.first, val);
		if (val > need)
		{
			need = val;
		}
	}
	return need;
}

int main()
{
	int n, i, a, b, x, y, t;
	while (scanf("%d", &n) == 1)
	{
		for (i=1; i<=n; i++)
		{
			v[i].clear();
		}
		for (i=1; i<n; i++)
		{
			scanf("%d%d%d%d", &a, &b, &x, &t);
			v[a].push_back({b, {x, t}});
		}
		for (i=1; i<=n; i++)
		{
			scanf("%d", &ary[i]);
		}
		printf("%.10lf\n", recurs(1));
	}
	return 0;
}