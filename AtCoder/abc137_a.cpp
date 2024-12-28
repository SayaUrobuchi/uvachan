#include <iostream>
using namespace std;

int main()
{
	int a, b;
	scanf("%d%d", &a, &b);
	int x = a + b;
	int y = a - b;
	int z = a * b;
	int ans = max(x, max(y, z));
	printf("%d\n", ans);
	return 0;
}
