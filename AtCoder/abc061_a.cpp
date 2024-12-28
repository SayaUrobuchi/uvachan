#include <iostream>
using namespace std;

int main()
{
	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);
	bool ans = (c >= a && c <= b);
	puts(ans ? "Yes" : "No");
	return 0;
}
