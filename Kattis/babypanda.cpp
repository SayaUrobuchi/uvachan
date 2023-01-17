#include <iostream>
using namespace std;

int main()
{
	int i;
	long long n;
	scanf("%*lld%lld", &n);
	for (i=0; n; i++, n-=(n&-n));
	printf("%d\n", i);
	return 0;
}
