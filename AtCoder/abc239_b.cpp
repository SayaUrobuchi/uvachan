#include <iostream>
using namespace std;

int main()
{
	long long n;
	scanf("%lld", &n);
	if (n >= 0)
	{
		printf("%lld\n", n/10);
	}
	else
	{
		printf("-%lld\n", (abs(n)+9)/10);
	}
	return 0;
}