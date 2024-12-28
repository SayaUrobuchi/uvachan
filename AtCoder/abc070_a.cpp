#include <iostream>
using namespace std;

int main()
{
	int a, b, c;
	scanf("%1d%1d%1d", &a, &b, &c);
	bool ans = (a == c);
	puts(ans ? "Yes" : "No");
	return 0;
}
