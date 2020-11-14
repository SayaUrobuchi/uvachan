#include <iostream>
#include <cmath>
#include <queue>
using namespace std;

using nod = pair<double, int>;

double px[128], py[128], dis[128];

double getdis(double x0, double y0, double x1, double y1)
{
	return sqrt((x0-x1)*(x0-x1)+(y0-y1)*(y0-y1));
}

double shot(int a, int b)
{
	double x, y, tx, ty, ang;
	x = px[b] - px[a];
	y = py[b] - py[a];
	ang = atan2(y, x);
	tx = px[a] + 50 * cos(ang);
	ty = py[a] + 50 * sin(ang);
	//printf("orig: %.10lf %.10lf to %.10lf %.10lf\n", px[a], py[a], px[b], py[b]);
	//printf("shot to %.10lf %.10lf\n", tx, ty);
	//printf("%d to %d: %.10lfs\n", a, b, getdis(tx, ty, px[b], py[b])/5.0 + 2.0);
	return getdis(tx, ty, px[b], py[b])/5.0 + 2.0;
}

int main()
{
	int n, i, cur;
	double sx, sy, ex, ey, d;
	while (scanf("%lf%lf%lf%lf", &sx, &sy, &ex, &ey) == 4)
	{
		scanf("%d", &n);
		for (i=0; i<n; i++)
		{
			scanf("%lf%lf", &px[i], &py[i]);
		}
		px[n] = ex;
		py[n] = ey;
		priority_queue<nod, vector<nod>, greater<nod> > pq;
		for (i=0; i<=n; i++)
		{
			dis[i] = getdis(sx, sy, px[i], py[i]) / 5.0;
			pq.push({dis[i], i});
		}
		while (!pq.empty())
		{
			nod now = pq.top();
			pq.pop();
			cur = now.second;
			if (cur == n)
			{
				break;
			}
			if (now.first != dis[cur])
			{
				continue;
			}
			//printf("%d %lf\n", cur, dis[cur]);
			for (i=0; i<=n; i++)
			{
				d = dis[cur] + shot(cur, i);
				if (d < dis[i])
				{
					dis[i] = d;
					pq.push({d, i});
				}
			}
		}
		printf("%.10lf\n", dis[n]);
	}
	return 0;
}
