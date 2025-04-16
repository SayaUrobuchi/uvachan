#include <iostream>
#include <cmath>
using namespace std;

const int N = 1024;

int ary[N], px[N], py[N];
bool light[N];

int main()
{
	int n, m, i, j;
	scanf("%d%d", &n, &m);
	for (i=0; i<m; i++)
	{
		scanf("%d", &ary[i]);
		light[ary[i]] = true;
	}
	for (i=1; i<=n; i++)
	{
		scanf("%d%d", &px[i], &py[i]);
	}
	double ans = 0;
	for (i=1; i<=n; i++)
	{
		double dis = 0;
		if (!light[i])
		{
			dis = 1e18;
			for (j=0; j<m; j++)
			{
				double dx = px[i] - px[ary[j]];
				double dy = py[i] - py[ary[j]];
				double d = sqrt(dx*dx + dy*dy);
				dis = min(dis, d);
			}
		}
		ans = max(ans, dis);
	}
	printf("%.10lf\n", ans);
	return 0;
}