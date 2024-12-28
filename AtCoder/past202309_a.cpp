#include <iostream>
using namespace std;

int main()
{
	int n;
	scanf("%d", &n);
	bool ans = (n >= 4 && n <= 9);
	puts(ans ? "Yes" : "No");
	return 0;
}
