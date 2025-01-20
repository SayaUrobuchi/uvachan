#include <iostream>
using namespace std;

int main()
{
	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);
	int l = max(a, max(b, c));
	int s = min(a, min(b, c));
	int ans = l - s;
	printf("%d\n", ans);
	return 0;
}
