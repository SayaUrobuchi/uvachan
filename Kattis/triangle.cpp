#include <iostream>
#include <cmath>

int main()
{
	int n, cas;
	cas = 0;
	while (scanf("%d", &n) == 1)
	{
		printf("Case %d: %d\n", ++cas, (int)(log10(3)+log10(1.5)*n+1));
	}
	return 0;
}
