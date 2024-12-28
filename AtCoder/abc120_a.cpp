#include <iostream>
using namespace std;

int main()
{
	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);
	int ans = min(c, b/a);
	printf("%d\n", ans);
	return 0;
}
