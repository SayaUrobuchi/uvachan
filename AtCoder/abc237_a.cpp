#include <iostream>
using namespace std;

int main()
{
	long long n;
	scanf("%lld", &n);
	bool inr = (n >= -2147483648LL && n < 2147483648LL);
	puts(inr ? "Yes" : "No");
	return 0;
}
