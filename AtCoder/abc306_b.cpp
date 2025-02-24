#include <iostream>
using namespace std;

int main()
{
	int i;
	unsigned long long ans = 0;
	for (i=0; i<64; i++)
	{
		int t;
		scanf("%d", &t);
		ans |= ((t * 1LL) << i);
	}
	printf("%llu\n", ans);
	return 0;
}
