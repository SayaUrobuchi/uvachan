#include <iostream>
using namespace std;

int main()
{
	int n;
	scanf("%d", &n);
	int ans = 0;
	while (n)
	{
		ans += (n % 10 == 2);
		n /= 10;
	}
	printf("%d\n", ans);
	return 0;
}