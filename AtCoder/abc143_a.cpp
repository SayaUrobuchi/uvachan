#include <iostream>
using namespace std;

int main()
{
	int a, b;
	scanf("%d%d", &a, &b);
	int ans = max(0, a-b-b);
	printf("%d\n", ans);
	return 0;
}
