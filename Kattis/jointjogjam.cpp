#include <iostream>
#include <cmath>
using namespace std;

double res[2];

int main()
{
	int i, x0, x1, y0, y1;
	for (i=0; i<2; i++)
	{
		scanf("%d%d%d%d", &x0, &y0, &x1, &y1);
		res[i] = sqrt((x0-x1)*(x0-x1)+(y0-y1)*(y0-y1));
	}
	printf("%.10lf\n", max(res[0], res[1]));
	return 0;
}
