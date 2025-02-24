#include <iostream>
using namespace std;

int main()
{
	int n;
	scanf("%d", &n);
	int even = n / 2;
	int odd = even + n % 2;
	int ans = even * odd;
	printf("%d\n", ans);
	return 0;
}
