#include <iostream>
using namespace std;

int main()
{
	int i;
	long long n;
	while (scanf("%lld", &n) == 1)
	{
		for (i=0; (1LL<<i)<=n; i++);
		printf("%d\n", i-1);
	}
	return 0;
}

