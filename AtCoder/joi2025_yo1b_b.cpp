#include <iostream>
using namespace std;

int main()
{
	int p, q, a, b;
	scanf("%d%d%d%d", &p, &q, &a, &b);
	int ans = min(p, q) * a + max(0, q-p) * b;
	printf("%d\n", ans);
	return 0;
}