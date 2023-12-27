#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int r;
	double s;
	while (scanf("%d%lf", &r, &s) == 2)
	{
		printf("%.0lf\n", sqrt(r*(s+.16)/.067));
	}
	return 0;
}