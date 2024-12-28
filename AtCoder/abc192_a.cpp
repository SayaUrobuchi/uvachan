#include <iostream>
using namespace std;

int main()
{
	int n;
	scanf("%d", &n);
	int ans = 100 - (n % 100);
	printf("%d\n", ans);
	return 0;
}
