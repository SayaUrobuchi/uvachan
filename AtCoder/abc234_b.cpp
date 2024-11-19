#include <iostream>
#include <cmath>
using namespace std;

const int N = 105;

int px[N], py[N];

int main()
{
	int n, i, j;
	scanf("%d", &n);
	double ans = 0;
	for (i=0; i<n; i++)
	{
		scanf("%d%d", &px[i], &py[i]);
		for (j=0; j<i; j++)
		{
			int x = px[i] - px[j];
			int y = py[i] - py[j];
			ans = max(ans, sqrt(x*x+y*y));
		}
	}
	printf("%.10lf\n", ans);
	return 0;
}