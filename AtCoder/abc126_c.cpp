#include <iostream>
using namespace std;

int main()
{
	int n, m, i, j;
	scanf("%d%d", &n, &m);
	double winr = 0;
	for (i=1; i<=n; i++)
	{
		double rate = 1. / n;
		for (j=i; j<m; j<<=1, rate/=2);
		winr += rate;
	}
	printf("%.10lf\n", winr);
	return 0;
}
