#include <iostream>
#include <cmath>
using namespace std;

double calc(int p, int a, int b, int c, int d, int k)
{
	return p * (sin(a*k + b) + cos(c*k + d) + 2);
}

int main()
{
	int p, a, b, c, d, n, i;
	double mx, t, ans;
	while (scanf("%d%d%d%d%d%d", &p, &a, &b, &c, &d, &n) == 6)
	{
		mx = calc(p, a, b, c, d, 1);
		ans = 0;
		for (i=2; i<=n; i++)
		{
			t = calc(p, a, b, c, d, i);
			ans = max(ans, mx-t);
			mx = max(mx, t);
		}
		printf("%.10lf\n", ans);
	}
	return 0;
}
