#include <iostream>
using namespace std;

int main()
{
	int c, a, b;
	scanf("%d%d%d", &c, &a, &b);
	int ans = min(a*c, b);
	printf("%d\n", ans);
	return 0;
}
