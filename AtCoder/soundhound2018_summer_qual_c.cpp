#include <iostream>
using namespace std;

int main()
{
	int dif, n, m;
	scanf("%d%d%d", &n, &m, &dif);
	int a, b;
	a = 1;
	b = n - dif;
	int sum = max(0, b-a+1) << (dif != 0);
	printf("%.10lf\n", sum*1.*(m-1)/n/n);
	return 0;
}
