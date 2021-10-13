#include <iostream>
using namespace std;

int main()
{
	int n, m;
	while (scanf("%d%d", &n, &m) == 2)
	{
		if (n == 1 || m == 1)
		{
			printf("%d\n", n*m);
		}
		else
		{
			printf("%d\n", ((m+1)>>1)*((n+1)>>1));
		}
	}
	return 0;
}
