#include <iostream>
using namespace std;

int main()
{
	int a, b, x;
	scanf("%d%d%d", &a, &b, &x);
	bool ans = (x >= a && x <= a+b);
	puts(ans ? "YES" : "NO");
	return 0;
}
