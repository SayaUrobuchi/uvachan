#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int n;
	scanf("%d", &n);
	double ans = sqrt(n*(n+12800000.));
	printf("%.10lf\n", ans);
	return 0;
}
