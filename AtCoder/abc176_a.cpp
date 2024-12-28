#include <iostream>
using namespace std;

int main()
{
	int n, x, t;
	scanf("%d%d%d", &n, &x, &t);
	int r = (n + x - 1) / x;
	int ans = r * t;
	printf("%d\n", ans);
	return 0;
}
