#include <iostream>
using namespace std;

int main()
{
	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);
	int mx = max(a, max(b, c));
	puts(a*b*c == mx*mx ? "Yes" : "No");
	return 0;
}
