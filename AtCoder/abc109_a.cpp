#include <iostream>
using namespace std;

int main()
{
	int a, b;
	scanf("%d%d", &a, &b);
	bool ans = (a & 1) && (b & 1);
	puts(ans ? "Yes" : "No");
	return 0;
}
