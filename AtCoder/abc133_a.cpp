#include <iostream>
using namespace std;

int main()
{
	int n, a, b;
	scanf("%d%d%d", &n, &a, &b);
	int ans = min(n*a, b);
	printf("%d\n", ans);
	return 0;
}
