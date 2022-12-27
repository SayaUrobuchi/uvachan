#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	long long n, i, j, sqn;
	scanf("%lld", &n);
	sqn = sqrt(n)+1e-7;
	for (i=sqn; i>1&&n%i; --i);
	for (i=n/i, j=1; i>9; i/=10, j++);
	printf("%d\n", j);
	return 0;
}