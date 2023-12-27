#include <iostream>
#include <cmath>
#include <tuple>
#include <vector>
#include <queue>
using namespace std;
using pp = pair<double, int>;

const int N = 1005;

bool used[N];
double px[N], py[N], dis[N];
vector<int> v[N];

inline double get_dis(double dx, double dy)
{
	return sqrt(dx*dx + dy*dy);
}

int main()
{
	int n, m, o, i, j, a, b;
	scanf("%d%d%d", &n, &o, &m);
	for (i=0; i<n; i++)
	{
		scanf("%lf%lf", &px[i], &py[i]);
		dis[i] = 1e100;
	}
	priority_queue<pp, vector<pp>, greater<pp> > pq;
	for (i=0; i<o; i++)
	{
		pq.emplace(0.0, i);
		dis[i] = 0;
	}
	for (i=0; i<m; i++)
	{
		scanf("%d%d", &a, &b);
		--a, --b;
		v[a].emplace_back(b);
		v[b].emplace_back(a);
	}
	double ans = 0;
	for (i=0; i<n; )
	{
		double d;
		int cur;
		tie(d, cur) = pq.top();
		pq.pop();
		if (used[cur])
		{
			continue;
		}
		++i;
		ans += d;
		used[cur] = true;
		for (j=0; j<v[cur].size(); j++)
		{
			int nxt = v[cur][j];
			if (!used[nxt] && dis[nxt] > 0)
			{
				dis[nxt] = 0;
				pq.emplace(0.0, nxt);
			}
		}
		for (j=o; j<n; j++)
		{
			double nd = get_dis(px[cur]-px[j], py[cur]-py[j]);
			if (!used[j] && dis[j] > nd)
			{
				dis[j] = nd;
				pq.emplace(nd, j);
			}
		}
	}
	printf("%.10lf\n", ans);
	return 0;
}
