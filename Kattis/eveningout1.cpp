#include <iostream>
using namespace std;

int main()
{
	long long a, b;
	scanf("%lld%lld", &a, &b);
	printf("%lld\n", min(a%b, b-a%b));
	return 0;
}
