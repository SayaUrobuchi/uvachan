#include <iostream>
#include <cmath>
using namespace std;

const int N = 2048;

int px[N], py[N];

int main()
{
	int n, i, j;
	scanf("%d", &n);
	double ans = 1e18;
	for (i=0; i<n; i++)
	{
		scanf("%d%d", &px[i], &py[i]);
		for (j=0; j<i; j++)
		{
			int dx = px[i] - px[j];
			int dy = py[i] - py[j];
			double d = sqrt(dx*1LL*dx + dy*1LL*dy);
			ans = min(ans, d);
		}
	}
	printf("%.10lf\n", ans);
	return 0;
}
