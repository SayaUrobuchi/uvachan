#include <iostream>
using namespace std;

int main()
{
	int n;
	scanf("%d", &n);
	int b = n / 2;
	int a = n - b;
	int ans = a * 3 - b * 2;
	printf("%d\n", ans);
	return 0;
}
