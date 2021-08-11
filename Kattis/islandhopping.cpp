#include <iostream>
#include <cmath>
#include <queue>
using namespace std;
using pp = pair<double, int>;

int ucnt;
int used[1024];
double px[1024], py[1024], dis[1024];

double getdis(double dx, double dy)
{
	return sqrt(dx*dx+dy*dy);
}

int main()
{
	int count, n, i, c;
	double d, ans;
	scanf("%d", &count);
	while (count--)
	{
		scanf("%d", &n);
		priority_queue<pp, vector<pp>, greater<pp> > pq;
		for (i=0; i<n; i++)
		{
			scanf("%lf%lf", &px[i], &py[i]);
			if (i)
			{
				dis[i] = getdis(px[i]-px[0], py[i]-py[0]);
				pq.emplace(dis[i], i);
			}
		}
		++ucnt;
		used[0] = ucnt;
		for (ans=0, c=n-1; pq.size()&&c; )
		{
			pp cur = pq.top();
			pq.pop();
			if (used[cur.second] == ucnt)
			{
				continue;
			}
			--c;
			used[cur.second] = ucnt;
			ans += cur.first;
			//printf("%d %.10lf %.10lf\n", cur.second, ans, cur.first);
			for (i=0; i<n; i++)
			{
				if (used[i] != ucnt)
				{
					d = getdis(px[i]-px[cur.second], py[i]-py[cur.second]);
					if (d < dis[i])
					{
						dis[i] = d;
						pq.emplace(d, i);
					}
				}
			}
		}
		printf("%.10lf\n", ans);
	}
	return 0;
}
