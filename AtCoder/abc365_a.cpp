#include <iostream>
using namespace std;

int main()
{
	int n;
	scanf("%d", &n);
	bool leap = (n % 400 == 0 || (n % 100 && n % 4 == 0));
	int ans = 365 + leap;
	printf("%d\n", ans);
	return 0;
}
