#include <iostream>
using namespace std;

int main()
{
	int a, b;
	scanf("%d%d", &a, &b);
	double ans = (a-b) * 100. / a;
	printf("%.10lf\n", ans);
	return 0;
}
