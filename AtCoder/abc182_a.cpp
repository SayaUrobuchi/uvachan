#include <iostream>
using namespace std;

int main()
{
	int a, b;
	scanf("%d%d", &a, &b);
	int limit = a + a + 100;
	int ans = limit - b;
	printf("%d\n", ans);
	return 0;
}
