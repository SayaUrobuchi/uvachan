#include <iostream>
using namespace std;

int main()
{
	int n, a, b;
	scanf("%d%d%d", &a, &b, &n);
	int ans = n;
	while (n >= a)
	{
		int t = n / a;
		ans += t * b;
		n = n % a + t * b;
	}
	printf("%d\n", ans);
	return 0;
}
