#include <iostream>
using namespace std;

int main()
{
	int a, b, i;
	long long ans;
	while (scanf("%d%d", &b, &a) == 2)
	{
		for (i=a+1, ans=1; i<=b; i++)
		{
			ans <<= 5;
		}
		printf("%lld\n", ans);
	}
	return 0;
}

