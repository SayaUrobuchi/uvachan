#include <iostream>
using namespace std;

int main()
{
	int n, i;
	scanf("%d", &n);
	int ans = 1e9;
	for (i=1; i*i<=n; i++)
	{
		int j = n / i;
		int rem = n - i * j;
		ans = min(ans, rem+(j-i));
	}
	printf("%d\n", ans);
	return 0;
}
