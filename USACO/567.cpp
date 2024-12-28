#include <iostream>
using namespace std;

int main()
{
	freopen("paint.in", "r", stdin);
	freopen("paint.out", "w", stdout);
	int a, b, c, d;
	scanf("%d%d", &a, &b);
	scanf("%d%d", &c, &d);
	int ans = (b-a) + (d-c);
	ans -= max(0, min(b, d)-max(a, c));
	printf("%d\n", ans);
	return 0;
}
