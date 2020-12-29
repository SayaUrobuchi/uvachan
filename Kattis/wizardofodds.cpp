#include <iostream>
#include <cmath>

int main()
{
	double n, m;
	while (scanf("%lf%lf", &n, &m) == 2)
	{
		puts(floor(log2(n-1))+1<=m?"Your wish is granted!":"You will become a flying monkey!");
	}
	return 0;
}
