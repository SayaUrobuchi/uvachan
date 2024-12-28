#include <iostream>
using namespace std;

int main()
{
	int a, b;
	scanf("%d%d", &a, &b);
	bool ans = (a + b*7 <= 30);
	printf("%d\n", ans);
	return 0;
}
