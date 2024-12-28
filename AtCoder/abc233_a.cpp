#include <iostream>
using namespace std;

int main()
{
	int a, b;
	scanf("%d%d", &a, &b);
	int ans = max(0, (b-a+9)/10);
	printf("%d\n", ans);
	return 0;
}
