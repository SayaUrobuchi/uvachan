#include <iostream>
#include <cmath>
using namespace std;

const double PI = acos(-1);

int main()
{
	int r;
	scanf("%d", &r);
	double ans = 2 * PI * r;
	printf("%.10lf\n", ans);
	return 0;
}
