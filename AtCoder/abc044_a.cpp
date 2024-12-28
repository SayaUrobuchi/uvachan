#include <iostream>
using namespace std;

int main()
{
	int n, k, x, y;
	scanf("%d%d%d%d", &n, &k, &x, &y);
	int ans = x * min(n, k) + y * max(0, n-k);
	printf("%d\n", ans);
	return 0;
}
