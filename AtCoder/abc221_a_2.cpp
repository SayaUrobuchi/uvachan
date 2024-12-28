#include <iostream>
using namespace std;

int main()
{
	int a, b;
	scanf("%d%d", &a, &b);
	int ans = (1 << ((a-b) * 5));
	printf("%d\n", ans);
	return 0;
}
