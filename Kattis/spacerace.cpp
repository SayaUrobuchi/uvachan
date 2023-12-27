#include <iostream>
using namespace std;

char buf[8];

int main()
{
	int n, i;
	double best;
	string best_nam;
	scanf("%d%*lf", &n);
	best = 1e300;
	for (i=0; i<n; i++)
	{
		double fuel;
		scanf("%s%*lf%lf", buf, &fuel);
		if (fuel < best)
		{
			best = fuel;
			best_nam = buf;
		}
	}
	puts(best_nam.c_str());
	return 0;
}
