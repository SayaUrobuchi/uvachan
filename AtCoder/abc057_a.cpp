#include <iostream>
using namespace std;

int main()
{
	int a, b;
	scanf("%d%d", &a, &b);
	int ans = (a+b) % 24;
	printf("%d\n", ans);
	return 0;
}