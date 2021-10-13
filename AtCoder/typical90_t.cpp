#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	long long a, b, c, t;
	while (scanf("%lld%lld%lld", &a, &b, &c) == 3)
	{
		for (t=1; b>0; b--, t*=c);
		puts(a<t?"Yes":"No");
	}
	return 0;
}
