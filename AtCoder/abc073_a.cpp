#include <iostream>
using namespace std;

int main()
{
	int a, b;
	scanf("%1d%1d", &a, &b);
	bool ans = (a == 9 || b == 9);
	puts(ans ? "Yes" : "No");
	return 0;
}
