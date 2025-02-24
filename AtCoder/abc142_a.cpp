#include <iostream>
using namespace std;

int main()
{
	int n;
	scanf("%d", &n);
	int odd = n / 2 + n % 2;
	int even = n / 2;
	double ans = odd / (odd + .0 + even);
	printf("%.10lf\n", ans);
	return 0;
}
