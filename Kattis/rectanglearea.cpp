#include <iostream>
using namespace std;

int main()
{
	double a, b, c, d;
	scanf("%lf%lf%lf%lf", &a, &b, &c, &d);
	printf("%.3lf\n", (max(a, c)-min(a, c)) * (max(b, d)-min(b, d)));
	return 0;
}
