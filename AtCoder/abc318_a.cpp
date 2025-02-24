#include <iostream>
using namespace std;

int main()
{
	int a, b, c;
	scanf("%d%d%d", &c, &a, &b);
	int ans = max(0, c-a) / b + (c >= a);
	printf("%d\n", ans);
	return 0;
}
