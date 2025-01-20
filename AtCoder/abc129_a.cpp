#include <iostream>
using namespace std;

int main()
{
	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);
	int ans = min(a+b, min(b+c, a+c));
	printf("%d\n", ans);
	return 0;
}
