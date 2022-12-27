#include <iostream>
using namespace std;

int main()
{
	int n, m;
	while (scanf("%d%d", &n, &m) == 2)
	{
		printf("%d\n", (m+1)*m/2*n+(n+1)*n/2*100*m);
	}
	return 0;
}

