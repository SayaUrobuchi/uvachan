#include <iostream>
using namespace std;

int main()
{
	int x, a, b;
	scanf("%d%d%d", &x, &a, &b);
	x -= a;
	x %= b;
	printf("%d\n", x);
	return 0;
}
