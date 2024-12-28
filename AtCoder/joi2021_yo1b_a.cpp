#include <iostream>
using namespace std;

int main()
{
	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);
	bool ans = (c >= a && c < b);
	printf("%d\n", ans);
	return 0;
}
