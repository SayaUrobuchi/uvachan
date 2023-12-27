#include <iostream>
using namespace std;

const int N = 1024;

int dis[N], spd[N];

int main()
{
	int n, m, i, j, best;
	scanf("%d%d", &n, &m);
	for (i=0, best=1e9; i<n; i++)
	{
		scanf("%d%d", &dis[i], &spd[i]);
		best = min(best, spd[i]);
	}
	double l, r, t;
	for (i=0, l=-best, r=1e18; i<200; i++)
	{
		double mid = (l+r) / 2;
		for (j=0, t=0; j<n; j++)
		{
			t += dis[j] / (spd[j]+mid);
		}
		if (t <= m)
		{
			r = mid;
		}
		else
		{
			l = mid;
		}
	}
	printf("%.10lf\n", l);
	return 0;
}
