#include <iostream>
using namespace std;

int main()
{
	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);
	int target = max(a, max(b, c));
	int ans = target * 3 - (a + b + c);
	printf("%d\n", ans);
	return 0;
}
