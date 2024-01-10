#include <iostream>
using namespace std;

char buf[8];

int main()
{
	int n, i;
	scanf("%d", &n);
	long long ans = 0;
	for (i=n-1; i>=0; i--)
	{
		scanf("%s", buf);
		ans |= (1LL << i) * (*buf == 'O');
	}
	printf("%lld\n", ans);
	return 0;
}
